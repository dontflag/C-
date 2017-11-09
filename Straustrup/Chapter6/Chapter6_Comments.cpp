// Chapter6_Comments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void clear_comments()
{
	

}


int main()
{
bool is_comment = 0;
string result = "", buf = "";
int qt_count = 0, double_qt_count = 0;
char ch;
	while (cin)
	{
		buf = "";
		cin.get(ch);
		buf += ch;
		switch (ch)
		{
		case char(39) : //кавычки
			qt_count++;
			break;
		case char(34) :
			double_qt_count++;
			break;
		case '/':
			{
				cin.get(ch);
				is_comment = ((ch == '/') || (ch == '*') && (qt_count % 2 == 0) && (double_qt_count % 2 == 0)); //коммент открывается и это не литерал
				if (!is_comment) //не комментарий - выдать полученный символ на вывод
					buf += ch;
				break;
			}
		case '*': //проверим, закрытие ли коммента?
			{
				cin.get(ch);
				is_comment = !(is_comment && (ch == '/') && (qt_count % 2 == 0) && (double_qt_count % 2 == 0)); //мы были в комменте, а теперь вышли
				if (!is_comment)
					buf.clear(); //вышли из комментария но в буфере звёздочка
				break;
			}
		case char(10) : //конец строки
			is_comment = 0;
		}
		if (!is_comment)
			result += buf;
		if (ch == 10)
			break;
		
	}
	cout << result;
	cin.get();
	return 0;
}

