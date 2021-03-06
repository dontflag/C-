﻿//This is a simply macropressor for C++
//It is able to expand macroses with and without arguments,
//but it is almost unable to check incorrect input data

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>


using namespace std;

enum TokenValue // просто другие имена для различных символов. Напр. curr_tok = ASSIGN
{
	NAME, NUMBER, END,
	PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
	PRINT = ';', ASSIGN = '=', LP = '(', RP = ')', LB = '{', RB = '}', COMMA = ',',
	DEFINE, END_OF_LINE = '\n'
};

struct macro
{
	string name;
	string definition;
	vector <string> args;
};

vector <macro> macroses;
istream* input; //указатель на поток ввода

TokenValue curr_tok = PRINT;

string string_value;
double number_value;
int no_of_errors = 0;

double error(const string& s)
{
	no_of_errors++;
	cerr << s << '\n';
	return 1;
}

TokenValue get_token(istream &aStream)
{
	string directive;
	char ch = 0;
	do // пропустить все пробельные символы кроме '\п'
	{
		if (!aStream.get(ch))
			return curr_tok = END;
	} while (ch != '\n' && isspace(ch));
	switch (ch)
	{
	case ';':
		return curr_tok = PRINT;
	}
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
	case '\n':
		return curr_tok = TokenValue(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case 'б': case '7': case '8': case '9':
	case '.':
		aStream.putback(ch);
		aStream >> number_value;
		return curr_tok = NUMBER;
	case '#':
		aStream.get(ch);
		if (isalpha(ch))
		{
			directive = ch;
			while (aStream.get(ch) && isalnum(ch))
				directive.push_back(ch);
			if (directive == "define")
				return curr_tok = DEFINE;
			else
				error("bad directive: " + directive);

		}
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

void fill_arg_list(vector<string>& aVec)
{
	while ((curr_tok != RP) && (curr_tok != PRINT) && (curr_tok != END))
		switch (get_token(*input))
		{
		case NAME:
			aVec.push_back(string_value);
		case COMMA: case RP:
			break;
		default:
			error("bad token: " + char(curr_tok));
		}
	if (curr_tok != RP)
		error("you should close argument list with a ')'");
}

void define()
{
string definition;
	get_token(*input);
	macroses.push_back({ string_value,"" });
	while ((curr_tok != PRINT) && (curr_tok != END))
	{
		switch (get_token(*input))
		{
		case NAME:
			definition += string_value;
			break;
		case NUMBER:
			definition += to_string(number_value);
			break;
		case END: case PRINT:
			break;
		case LP: //есть список аргументов
			fill_arg_list(macroses[macroses.size() - 1].args);
			break;
		default:
			definition += char(curr_tok);
		}
	}
	macroses[macroses.size() - 1].definition = definition;
};

void expand()
{
bool def_passed = false;
string result, sub_res;
vector <string> user_args;
short pos = 0, prev_pos = 0;
	while ((curr_tok != END) && (curr_tok != END_OF_LINE))
	{
		switch (curr_tok)
		{
		case NAME:
			for (short i = 0; i < macroses.size(); i++)
				if (macroses[i].name == string_value)
				{
					def_passed = true;
					if (macroses[i].args.size()==0)
						cout << macroses[i].definition;
					else
					{
						switch (get_token(*input))
						{
						case LP: //заполняем список пользовательских аргументов
							fill_arg_list(user_args);
							break;
						default:
							error("you have to write an arg_list for this macro call!");
						}
						for (short j = 0; j < macroses[i].args.size(); j++)
						{
							pos = 0;
							sub_res = macroses[i].definition.substr(pos, macroses[i].definition.length());
							while (pos != sub_res.npos)
							{
								pos = sub_res.find(macroses[i].args[j]);
								if (pos != sub_res.npos) //есть вхождение
								{
									if (((pos == 0) || (!isalnum(sub_res[pos - 1])) && !isalnum(sub_res[pos + macroses[i].args[j].length()])));
									{
										sub_res.replace(pos, macroses[i].args[j].length(), user_args[j]); //заменили в исходной строке идентификаторы
										result += sub_res.substr(prev_pos,user_args[j].length()+pos-prev_pos); //добавили предыдущие символы + новый идент в макрос
										sub_res = sub_res.substr(pos + user_args[j].length(), sub_res.length()); //получили остаток неисследованной строки
										prev_pos = pos + macroses[i].args[j].length(); //получили позицию, с которой добавлять в резалт
									}

								}
							}
						}
						cout << result;
					}
					break;
				}
			if (!def_passed)
				cout << string_value;
			break;
		case NUMBER:
			cout << number_value;
			break;
			default:
			cout << char(curr_tok);
		}
		get_token(*input);
	}
};



int main(int argc, char* argv[])
{
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
		else if (curr_tok == DEFINE)
			define();
		else
			expand(); //тут будем анализировать строку, и искать, есть ли что экспандить.
		/*cout << expr(false) << "\n";
		cur_row++;*/
	}
	if (input != &cin)
		delete input;
	return no_of_errors;
}
