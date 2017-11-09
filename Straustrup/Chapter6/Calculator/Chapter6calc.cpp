// Chapter6calc.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>


/*program: - т.н. формальная грамматика программы
	END // END это конец ввода 
	expr_list END
expr_list :
	expression PRINT // PRINT это точка с запятой 
	expression PRINT expr_list
expression : // выражение 
	expression + term
	expression - term
	term
term :
	term / primary
	term * primary
	primary
primary : // первичное выражение 
	NUMBER // число 
	NAME // имя 
	NAME = expression
	- primary
	(expression)*/

using namespace std;

enum TokenValue // просто другие имена для различных символов. Напр. curr_tok = ASSIGN
	{
		NAME, NUMBER, END,
		PLUS = '+', MINUS = '-', MUL = '*',  DIV='/' , 
		PRINT = ';', ASSIGN = '=', LP = '(' , RP= ')', LB = '{', RB = '}',COMMA = ',' 
	};
TokenValue curr_tok = PRINT;
double number_value;
string string_value;
int no_of_errors, cur_row=1, inp_row=1;
map<string, double> table;
map<string, string> funcs; // <идентификатор,текст> пользовательских функций
istream* input; //указатель на поток ввода 

double error(const string& s)
{
	no_of_errors++;
	cerr << "error in the row " << inp_row << ": " << s << '\n';
	cur_row++;
	return 1;
}

TokenValue get_token(istream &aStream)
{
	char ch = 0;
	do // пропустить все пробельные символы кроме '\п'
	{
		if (!aStream.get(ch))
			return curr_tok = END;
	} while (ch!= '\n' && isspace(ch));
	switch (ch)
	{
	case '\n':
		cur_row++;
		inp_row = cur_row; //именно тут мы определяем, что пользователь закончил вводить свою строку, значит можно обновлять номер строки-условия
	case ';':
		return curr_tok = PRINT;
	}
	//cin >> ch; - мы уже получаем ch тут - if (!cin.get(ch)) 
	switch (ch)
	{
	case 0:
		return curr_tok = END;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
	case '{':
	case '}':
	case ',':
 		return curr_tok = TokenValue(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case 'б': case '7': case '#': case '9':
	case '.':
		aStream.putback(ch);
		aStream >> number_value;
		return curr_tok = NUMBER;
	default: //NAME, NAME =, или ошибка 
		if (isalpha(ch))
		{
			string_value = ch;
			while (aStream.get(ch) && isalnum(ch)) 
				string_value.push_back(ch);
			aStream.putback(ch);
			return curr_tok = NAME;
		}
		error("bad token");
		return curr_tok = PRINT;
	}
}

double expr(bool);
double func();

double prim(bool get) // обработка первичных выражений 
{
	if (get) 
 		get_token(*input);
	switch (curr_tok)
	{
	case NUMBER:
	{
		double v = number_value;
		get_token(*input);
		return v;
	}
	case NAME:
	{
		double &v = table[string_value];
		if (get_token(*input) == ASSIGN)
			v = expr(true); //если после идентификатора идёт '(', а не '=', то это определение пользовательской функции
		else if (curr_tok == LP)
			v = func();
		return v;
	}
	case MINUS: //унарный минус 
		return -prim(true);

	case LP:
	{
		double e = expr(true);
		if (curr_tok != RP) return error(" ')' expected");
		get_token(*input); // пропустить ')' 
		return e;
	}
	default:
		return error("primary expected");
	}
}

double term(bool get) //умножение и деление 
{
double left = prim(get);
	for (; ; )
		switch (curr_tok)
		{
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true))
			{
				left /= d;
				break;
			}
			return error( "divide by 0" );
		default:
			return left;
	}
}

double expr(bool get) // сложение и вычитание 
{
double left = term(get);
	for(; ; ) //"вечно" 
		switch (curr_tok)
		{
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left -= term(true);
			break;
		default:
			return left;
		}
}

double func()
{
string func_name = string_value;
map<string, string>::iterator it = funcs.find(func_name); //получили в it элемент с ключом string_value, либо последний
bool params_passed = 0; //обнуляем тут, т.к. один вызов - одна функция, один набор параметров
double res = 0;
vector<pair<string,double>> params; //список параметр = значение (if any)
	if ((funcs.empty()) || (((it == funcs.end()) /*&& (funcs.end()->first != func_name)*/))) //функции нет в списке - вносим. END() указывает не на последний элемент списка, а на следующую ячейку памяти за последним элементом
	{
	string func_def="(";
		do
		{
			switch (get_token(*input))
			{
			case NAME:
				func_def += string_value;
				break;
			case NUMBER:
				func_def += to_string(number_value);
				break;
			case END:
				return error("unexpected end of function definition");
				break;
			default:
				func_def += char(curr_tok);
			}
		} 
		while (curr_tok != RB);
		funcs.insert(std::pair<string, string>(func_name, func_def));
	}
	else { //вызов функции - заполняем параметры. Возможное несоответствие количества опустим
	string param_name;
		for (short i = 1; funcs[func_name][i]!=')'; i++) //1, чтобы пропустить '('
		{
		
			if (funcs[func_name][i] == ',')
			{
				get_token(*input); //получили значение параметра
				params.push_back(std::make_pair(param_name, number_value));
				param_name = "";
				get_token(*input); //пропустили запятую в списке параметров
			}
			else 
				param_name += funcs[func_name][i];
		}
		if (param_name != "") //параметр один, либо вносим последний
		{
			get_token(*input); //получили значение параметра
			params.push_back(std::make_pair(param_name, number_value));
			param_name = "";
			get_token(*input); //пропустили ')'
			string param_str;
			for (short j = 0; j < params.size(); j++)
			{
				param_str += params[j].first += "=";
				param_str += to_string(params[j].second) += ";"; //to_string работает только в C++11
			}
			istringstream param_stream(param_str);
			input = &param_stream;
			while (param_stream)
			{
				get_token(param_stream);
				if ((curr_tok == END) || (curr_tok == RB))
					break;
				if (curr_tok == PRINT)
					continue;
				expr(false);
			}
		}
	}
	istringstream func_stream(funcs[func_name]);
	input = &func_stream;
	while (func_stream)
	{
		if (!params_passed) //пропустим (проанализируем) параметры
		{
			while (curr_tok != LB)
				get_token(func_stream);
			params_passed = 1;
		}
		get_token(func_stream);
		if ((curr_tok == END) || (curr_tok == RB))
			break;
		if (curr_tok == PRINT)
			continue;
		res = expr(false);
	}
	input = &cin;
	return res;
}


int main(int argc, char* argv[])
{
table["pi"] = 3.1415926535897932385;
table["e"] = 2.7182818284590452354;
 	switch (argc)
	{
	case 1:
		input = &cin;
		break;
	case 2:
		input = new istringstream(argv[1]);
		break;
	default:
		error("too many arguments");
		return 1;
	}
	while (*input)
	{
		get_token(*input);
		if (curr_tok == END)
			break;
		if (curr_tok == PRINT) 
			continue;
		cout << expr(false) << "\n";
		cur_row++;
	}
	if (input!= &cin) 
		delete input;
	return no_of_errors;
}

