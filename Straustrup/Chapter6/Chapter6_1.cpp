// Chapter6.cpp: определяет точку входа для консольного приложения.
//
/*Перепишите следующий цикл for в виде эквивалентного while цикла: 
for{i=0; i<max length; i++) 
if {input line [i]=='?') quest count++; 
Перепишите так, чтобы проверяемой величиной был указатель и условие 
цикла имело вид *р==' ?' .  */

#include "stdafx.h"
#include <string>
//#include <iostream> - оно в stdafx.h
#include "Chapter6_3.h"
#include "Chapter6_5-8.h"
#include "Chapter6_10.h"

using namespace std;

void test() {}


int main()
{
string input_line = "abcdef?ghij?klmn?op";
short i = 0, quest_count = 0;
int max_length = input_line.length();
char* p = &input_line[0];
	do 
	{
		if (input_line[i] == '?')
			quest_count++;
		i++;
	} while (i < max_length);
	cout << quest_count << "\n";
	do
	{
		if (*p == '?')
			quest_count++;
		p++;
	} while (p < &input_line[max_length]);
	cout << quest_count << "\n";
	Chapter6_3();
	Chapter6_5_8();
	Chapter6_10();
	cin >> p;
	return 0;
}

