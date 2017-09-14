// Chapter5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>

typedef unsigned char uchar;
typedef const unsigned char cuchar;
typedef signed char schar;
typedef int* pint;
typedef char** PPchar;
typedef char* Pchar; //указатель на массив = указателю на нулевой элемент массива, который имеет тип char
typedef int* Int7Arr[7]; //массив из 7 указателей на int
typedef int* (*fp) (void); //указатель на функцию, возвращающую int*
//Объявление typedef для функции: typedef <возвращаемое значение> (<имя>) (void)
typedef int* (*PInt7Arr)[7]; //указатель на массив из 7 указателей на int
//для указателя на массив - <тип элементов массива> (* + идентификатор) [] - количество элементов, или пустые скобки для любого. В случае пустых скобок инициализация: IntArr a = {1,2,3]
typedef Int7Arr TwoDimArr[2]; //указатель на массив из двух массивов по 7 указателей 

using namespace std; //например, для использования string надо этот namespace объявить
char Symb = 's';
char* test1 = 0;
pint test2 = 0;
char* SymbPtr = test1; //указатель на char-переменную, УКАЗАТЕЛЬ ИНИЦИАЛИЗИРУЕТСЯ АДРЕСОМ, или нулём, или другим указателем
int Arr[] = { 0,6,7,3,45,67,89,4,1,2 }; //массив из 10 int
Int7Arr Arry = { &Arr[0],&Arr[1],&Arr[2],&Arr[3],&Arr[4],&Arr[5],&Arr[6] };
PInt7Arr arrP;
TwoDimArr ArrT = {
	{ &Arr[0],&Arr[1],&Arr[2],&Arr[3],&Arr[4],&Arr[5],&Arr[6] },
	{ &Arr[6],&Arr[5],&Arr[4],&Arr[3],&Arr[2],&Arr[1],&Arr[0] }
};
char StrArr[][7] = { //двумерный массив можно рассматривать, как массив строк; [7] потому что в таких массивах последний символ неявный: "\0"
	{"boris"}, //объявления "строк" массива равносильны
	{"has"},
	{'g','o','n','e'},
	{'t','o'},
	{"the"},
	{"toilet"} 
};
char* p1 = StrArr[0]; //указатель на этот массив (т.е. его нулевой элемент)
string str[6] = { "boris","has","gone","to","the","toilet" }; //тоже массив строк
string* p2 = str; //указатель на массив строк
PPchar symbpointer; //указатель на указатель
int test = 1;
const int c1 = 55; //int константа
const int* PointerOnTheConst = &test; //указатель на константу, УКАЗАТЕЛЬ ИНИЦИАЛИЗИРУЕТСЯ АДРЕСОМ, или нулём, или другим указателем
//const int* PointerOnTheConst = &c1; - так тоже можно
int* const ConstPointer = &test; //константный указатель, УКАЗАТЕЛЬ ИНИЦИАЛИЗИРУЕТСЯ АДРЕСОМ, или нулём, или другим указателем
//int* const ConstPointer = &c1; - а так нельзя
/*Значение объекта, по константному указателю, менять можно, а адрес - нельзя. Поэтому мы не можем инициализировать ConstPointer ссылкой на c1. Потому что тогда по ConstPointer нельзя будет менять значение
Значение объекта по указателю на константу менять нельзя, а адрес - можно.
Обращаясь к переменной test через PointerOnTheConst мы не можем менять её значение, а, обратившись напрямую к test - можем*/
SYSTEM_INFO SysInfo;

//task 7 decls
char Months[][10] = {
	{"january"},
	{"february"},
	{"march"},
	{"april"},
	{"may"},
	{"june"},
	{"july"},
	{"august"},
	{"september"},
	{"october"},
	{"november"},
	{"december"}
};

int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

struct month {
	string name;
	int days;
};

month MonthsStruct[] = {
	{Months[0],31 },
	{Months[1],28},
	{Months[2],31},
	{Months[3],30},
	{Months[4],31},
	{Months[5],30},
	{Months[6],31},
	{Months[7],31},
	{Months[8],30},
	{Months[9],31},
	{Months[10],30},
	{Months[11],31}

};

//task 10 decl

string MonthsStr[] = { "january","february","March","April","May","June","July","August","September","October","November","December" };

//task 12 decl
string Str = "aabbbhjjklok";
char ChrArr[] = "aabbbhjjklok";

//task 13 decl

struct Date {
	short day;
	short month;
	short year;
	Date operator = (Date &val) { //ни к чему создавать новый локальный объект, когда можно воспользоваться "другим именем" старого
		 this->day = val.day, this->month = val.month, this->year = val.year;
		 return *this; //ни к чему создавать новый объект, когда можно вернуть референс на старый
	}
};



//task 4 defs
void SwapWithLinks(int& a, int& b)
{
	int buf = a;
	a = b;
	b = buf;

}

void SwapWithPointers(int *a, int *b)
{
	int buf = *a;
	*a = *b;
	*b = buf;
}

//task 6 defs
void f(char a){}
void g (char &a){}
void h(const char &a){}

//task 7 def
void OutputMonths()
{
	for (short i = 0; i < sizeof(Months)/10; i++)
		cout << Months[i] << " contains " << days[i] << " days\n";
	for (short i = 0; i < sizeof(MonthsStruct) / sizeof(month); i++) 
		cout << month(MonthsStruct[i]).name << " contains " << month(MonthsStruct[i]).days << " days\n";
}

//task 10 def
void OutputArr(string Arr[])
{
	for (short i = 0; i < 12; i++)
		cout << Arr[i] << "\t";
	cout << "\n";
}

//task 11 def

bool CompareStr(const string* str1, const string* str2) //аргументы функции создаются, как локальные переменные. И уничтожаются, при выходе из функции. Зачем плодить копию массива?
{ //const тут означает, что функция не может изменять параметры.
int Length = str2->length();
bool LessStr = str1->length() <= str2->length();
bool LessVal = true;
	if (LessStr) 
		Length = str1->length();
	for (int i = 0; i < Length - 1; i++)
	{
		LessVal = ((LessVal) && ((*str1)[i] <= (*str2)[i])); //тут неявное преобразование (*str)[i] в численное значение
		if ((*str1)[i] != (*str2)[i])    //str1[i] - возвращало бы весь массив, тк указатель не разыменован
			break;
	}
	if (!LessVal) //что-то в str2 таки больше
		return false;
	else
		return true;
}

void SortVector(vector <string> &Source)
{ //сортируем в алфавитном порядке пузырьком
string buf;
for (int i = 0; i < Source.size(); i++)
for (int j = 0; j < Source.size() - 1; j++)
	if (!CompareStr(&(Source[j]), &(Source[j + 1]))) //тут типы автоматически приводятся
	{
		buf = Source[j + 1];
		Source[j + 1] = Source[j];
		Source[j] = buf;
	}
}

void task11()
{
	vector <string> Source;
	string inp;
	vector<string>::iterator it;
	//vector.back() - ссылка; vector.begin/end() - итератор; pop_back не возвращает значение; find возвращает итератор( в случае использования вектора), с массивом - указатель соответствующего типа
	do
	{
		cin >> inp;
		if (Source.size() > 0)
			it = find(Source.begin(), Source.end(), inp); //find возвращает либо найденное совпадение, либо последний элемент
		if (Source.empty())
			Source.push_back(inp);
		else if ((it == Source.end()) && (Source.back() != inp))//можно еще использовать find и search. Они возвращают либо найденный элемент, либо последний. Search может искать группы промежутков
			Source.push_back(inp);
	} while (inp != "Quit");
	Source.pop_back(); //удалим Quit
	SortVector(Source);
	for (short i = 0; i < Source.size(); i++) //тут тип автоматически приводится
		cout << Source[i] << "\t";
}

//task 12 defs

void task12(const string* str)
{
	int i = 0, j = 0;
	string CurSrc;
	struct pair {
		string src;
		int cnt;
		bool operator == (const pair &val) const { //оператор "==" умеет работать только с простыми типами. Для пользовательских надо ручками перегружать. Объявление только в теле структуры/класса
			return ((this->src == val.src) && (this->cnt == val.cnt));
		}
	};

	vector <pair> PairsLst;
	vector<pair>::iterator it;
	pair CurPair;
	cout << "\n";
	for (i = 0; i < str->length() - 1; i++) //создали список пар
	{
		CurPair = { { (*str)[i] , (*str)[i + 1] }, 0 };
		it = find(PairsLst.begin(), PairsLst.end(), CurPair);
		/*добавление, с проверкой на дубликаты*/
		if (PairsLst.empty())
			PairsLst.push_back(CurPair);
		else if ((it == PairsLst.end()) && PairsLst.back().src != CurPair.src)//можно еще использовать find и search. Они возвращают либо найденный элемент, либо последний. Search может искать группы промежутков
			PairsLst.push_back(CurPair);
	}
	for (j = 0; j < PairsLst.size() - 1; j++)
	{
		for (i = 0; i < str->length() - 1; i++)
		{
			CurSrc = { (*str)[i],(*str)[i + 1] };
			if (PairsLst[j].src == CurSrc) //и тут тип структуры не нужен
				PairsLst[j].cnt = PairsLst[j].cnt++;
		}
		cout << "Pair - " << PairsLst[j].src << " Count - " << PairsLst[j].cnt << "; ";
	}
	cout << "\n";
}
template<std::size_t N>
void task12Arr(char (&ChrArr)[N]) //ссылка на массив, размер надо явно указывать, либо через шаблон
{
	int i = 0, j = 0;
	struct pair {
		string src;
		int cnt;
		bool operator == (const pair &val) const { //оператор "==" умеет работать только с простыми типами. Для пользовательских надо ручками перегружать. Объявление только в теле структуры/класса
			return ((this->src == val.src) && (this->cnt == val.cnt));
		}
	};
	vector <pair> PairsLst;
	string CurSrc;
	vector<pair>::iterator it;
	pair CurPair;
	for (i = 0; i < sizeof(ChrArr) - 2; i++) //создали список пар; "-2", т.к. терминальный ноль учитываться не должен
	{
		CurSrc = { ChrArr[i] , ChrArr[i + 1] }; //ChrArr[i] + ChrArr[i + 1] - суммирует char коды, и на выходе мы получаем третий символ
		CurPair = { CurSrc,0 };
		it = find(PairsLst.begin(), PairsLst.end(), CurPair);
		/*добавление, с проверкой на дубликаты*/
		if (PairsLst.empty())
			PairsLst.push_back(CurPair);
		else if ((it == PairsLst.end()) && PairsLst.back().src != CurPair.src)
			PairsLst.push_back(CurPair);

	}
	for (i = 0; i < PairsLst.size() - 1; i++)
	{
		for (j = 0; j < sizeof(ChrArr)-2; j++)
		{
			CurSrc = { ChrArr[j] , ChrArr[j + 1] } ;
			if (PairsLst[i].src == CurSrc) //и тут тип структуры не нужен
				PairsLst[i].cnt = PairsLst[i].cnt++;
		}
		cout << "Pair - " << PairsLst[i].src << " Count - " << PairsLst[i].cnt << "; ";
	}
	cout << "\n";
}

//task 13 defs
Date DateInit(short* day, short* month, short* year)
{
	Date Cur = { *day,*month,*year };
	return Cur;
}


Date GetDate()
{
	short day, month, year;
	Date Cur;
	cout << "enter the date: "; //разбиение идёт автоматом по пробелу
	cin >> day >> month >> year;
	return Cur = DateInit(&day, &month, &year);
}

void OutDate(Date* OutDate)
{
	cout << "You have inputted this date: " << OutDate->day << OutDate->month << OutDate->year;
}





int main()
{
	int a=1, b=2;
	uchar Uch='U';
	schar Sch='S';
	GetSystemInfo(&SysInfo); //каждый адрес занимает одно машинное слово (8 байт - для х64 приложений; 4 байта - для х86)
	Date CurDate;
	cout << "Min - " << SysInfo.lpMinimumApplicationAddress << "\n"; //минимальный адрес, доступный для приложений
	cout << "Max - " << SysInfo.lpMaximumApplicationAddress << "\n"; //максимальный адрес, доступный для  приложений.
	for (short i = 0; i < sizeof(Arry) / sizeof(Arr[0]); i++) 
	{
		cout << *Arry[i] << "\t"; //* по отношению к объекту-ссылке получает значение по этой ссылке
	}
	for (short i = 0; i < sizeof(ArrT) / sizeof(Arry); i++)
	{
		cout << "\n";
		for (short j = 0; j<7;j++)
			cout <<*ArrT[i][j]<< "\t";
	}
	cout << "\n";
	/*cout << "Input first number" << "\n";
	cin >> a;
	cout << "Input second number" << "\n";
	cin >> b;*/
	//task 4
	SwapWithLinks(a, b); //передаём обычные параметры, но, в объявлении функции стоит &, что означает, что функция не создаёт себе внутренние копии аргументов, а изменяет поданные, беря их адресю
	cout << "\n" << a << "\t" << b << "\n";
	SwapWithPointers(&a, &b); //а тут параметры функции - указатели. Указатели надо инициализировать ссылками. Функция создаёт внутренние копии параметров-указателей, однако они имеют тот же адрес, что и передаваемые ссылки
	cout << "\n" << a << "\t" << b << "\n";
	//task 5
	char str[] = "a short string";
	cout << "size of char arr - " << sizeof(str) << "\n"; //15 - в char массивах есть неявный элемент: "\0"
	string StrStr = "a short string11";
	cout << "length of string - " << StrStr.length() << "\n"; //16
	//task 6
	f('a'); //и тут временная переменная создаётся (аргумент функции)
	f(49);
	f(3300); //вызов допустим, но производится усечение, тк числовая интерпретация char - -128-127 (зависит от компилятора)
	f(str[0]);
	f(Uch);
	f(Sch);
//	g('a'); //вызов недопустим: ссылку можно инициализировать только объектом того же типа, на который ссылка, адрес которого можно получить
//	g(49);//вызов недопустим: ссылку можно инициализировать только объектом того же типа, на который ссылка, и адрес которого можно получить
//	g(3300); //вызов недопустим, но производится усечение, тк числовая интерпретация char - -128-127 (зависит от компилятора)
	g(str[0]);
	//g(Uch); //вызов недопустим: ссылку можно инициализировать только объектом того же типа, на который ссылка, и адрес которого можно получить
	//g(Sch); //вызов недопустим: ссылку можно инициализировать только объектом того же типа, на который ссылка, и адрес которого можно получить
	h('a'); //во всех случаях функции h неявно создаётся временная переменная char, а несоответствующие значения неявно к ней приводятся
	h(49);  //эта переменная и инициализирует const char& параметр
	h(3300); //вызов допустим, но производится усечение, тк числовая интерпретация char - -128-127 (зависит от компилятора)
	h(str[0]);
	h(Uch);
	h(Sch);

	//task 7
	OutputMonths();

	cout << "\n";

	//task 8
	OutputArr(MonthsStr);

	//task 11
	task11();

	//task12
	task12(&Str);
	task12Arr(ChrArr);

	//task13
	CurDate = GetDate();
	OutDate(&CurDate);
		
	cin >> Symb;
	return 0;
}

