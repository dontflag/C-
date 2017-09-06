// Chapter41.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <complex>
#include <limits>

using namespace std;

char ch = '5';
string s = "sss";
int count=1;
extern const double pi;
int error_number; //extern - значит объявляется в другом месте
extern const char* name;
const char* season[4];
struct Date;
extern int day(Date* p);
double sqrt(double) { return 0.7; };
template<class T> extern T abs(T a);
typedef complex <short> Point; //complex <short> - описание одного типа данных, т.е. <short> - не параметр typedef; typedef не переделывается без определения
struct User
{
	int ID; //поля в структуре целесообразно располагать в порядке убывания длины типов - https://habrahabr.ru/post/90580/
	string Name;
};
enum Beer: unsigned int; //предварительное объявление перечислений (со стандарта С++ 11) unsigned int - >=0
enum en2 {min = -10, max=100000};
namespace NS { extern int a; }; //"a" будет определена позже

/*std::endl очищает буфер. "\n" же просто пихает в поток символ начала новой строки, и большинстве случаев это и требуется.А когда надо, можно отдельно вызвать cout<<flush, один раз.*/

/*в нижестоящих методах, непосредственно char можно передавать как счётчик: for (char ch = '0'; ch <= '9'; ch++)*/
void OutputLetters()
{
	for (short i = short('a'); i <= short('z'); i++) //в таблице ASCII все латинские символы идут подряд	 
	{
		cout << char(i) << "-" << i << " hexadecimal -" << hex << i << "\t";
		dec(cout); //вернуть i в десятичную
	}
}

void OutputNumbers()
{
	for (short i = short('1'); i <= short('9'); i++) 
	{
		cout << char(i) << "-" << i << " hexadecimal - " << hex << i << "\t";
		dec(cout);
	}
}

void OutputOthers()
{
	cout << "\n";
	for (short i = 156; i <= 166; i++)
	{
		cout << char(i) << " ASCII CODE - " << i << " hexadecimal - " << hex << i << "\t";
		dec(cout);
	}
}

void DTSize()
{
	cout << "\n";
	cout << "largest char==" << short(numeric_limits<char>::max())
		<< ", smallest char==" << short(numeric_limits<char>::min())<<"\n";
	cout << "largest short==" << numeric_limits<short>::max()
		<< ", smallest short ==" << numeric_limits<short>::min() << "\n";
	cout << "largest int==" << numeric_limits<int>::max()
		<< ", smallest int ==" << numeric_limits<int>::min() << "\n";
	cout << "largest long==" << numeric_limits<long>::max()
		<< ", smallest long ==" << numeric_limits<long>::min() << "\n";
	cout << "largest float==" << numeric_limits<float>::max()
		<< ", smallest float ==" << numeric_limits<float>::min() << "\n";
	cout << "largest double==" << numeric_limits<double>::max()
		<< ", smallest double ==" << numeric_limits<double>::min() << "\n";
	cout << "largest long double ==" << numeric_limits<long double>::max()
		<< ", smallest long double ==" << numeric_limits<long double>::min() << "\n";
	cout << "largest unsigned==" << numeric_limits<unsigned>::max()
		<< ", smallest unsigned ==" << numeric_limits<unsigned>::min() << "\n";
}


int main()
{
	char test;
	User UserExample;
	cout << "Hello! \n";
	//размер типа данных
	cout << "char size - " << sizeof(char) << "\n";
	//размер указателя, как типа данных
	cout << "ptr as datatype size -" << sizeof(void*) << "\n";
	//размеры переменных фундаментальных типов
	cout << "int size - " << sizeof(::count) << "\n"; //:: - глобальная переменная, а не какая-то там Си-функция
	cout << "char size - " << sizeof(ch) << "\n";
	cout << "Structure part size - " << sizeof(UserExample.ID) << "\n"; //нельзя объявлять структуру "на бегу". 
															//Как происходит инициализация структуры? Память под элементы выделяется при объявлении её экземпляра, элементы располагаются в памяти в порядке объявления
	//размеры указателей
	cout << "ptr size - " << sizeof(name) << "\n"; //в 32-битном приложении любой указатель имеет размер 4 байта, в 64-битном - 8 байт
	cout << "arr with ptr els size -" << sizeof(season) << "\n"; //массив из 4х указателей, по 4 байта каждый
	//размеры перечисления
	cout << "size of unsigned enum - " << sizeof(Beer) << "\n";
	cout << "size of defined enum -" << sizeof(en2) << "\n"; //enum - не переменные. То есть память под каждое значение не выделяется. Это способ сохранить числа в более читабельном формате (более красивая форма #define a 0). 
															 //Для компилятора все эти названия все равно будут числами. Размер enum аналогичен размеру int и равен 4	
	OutputLetters();
	cout << "\n";
	OutputNumbers();
	OutputOthers();
	DTSize();
	cin >> test;											
	return 0;
}



