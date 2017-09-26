#include "stdafx.h"
#include "Chapter6_10.h"

using namespace std;

short strlen_(const char* s1)
{ //передаём указатель на первый элемент массива, и приращиваем до тех пор, пока не будет терминальный нуль
short i = 0;
	for (i = 1; *s1 != '\0'; i++) //терминальный нуль
		++s1;
	return i;
}

void strcpy_(char* s1, const char* s2) 
{
	for (const char* p = s2; *p != '\0'; ++p)
	{
		*s1 = *p;
		++s1;
	}
	*s1 = '\0'; //левые символы уводим, но вместимость все равно остаётся 20
}

bool strcmp_(const char* s1, const char* s2)
{
	if (strlen_(s1) != strlen_(s2))
		return false; //длина разная => строки разные
	else
	{
		for (const char* p = s2; *p != '\0'; ++p)
		{
			if (*s1 != *p)
				return false;
			++s1;
		}
	}
	return true;
}

void Chapter6_10()
{
char s1[]="abcdefghi", s2[] = "hijklmnop";
	cout << strlen_(s1) << "\n";
	strcpy_(s1,s2);
	cout << "copied string: " << s1 << "\n";
	bool check = strcmp_(s1, s2);
	cout << "compare check: " << check << "\n";

}