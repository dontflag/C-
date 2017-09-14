// Chapter58arraysiteration.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <WinBase.h>
#include <vector>

using namespace std;
char v[] = "boris_na_buyu_povis";
SYSTEMTIME st;

void ind(char v[])
{
int prevtime = 0;
int sum = 0;
vector <int> times;
	/*GetSystemTime(&st);
	cout << st.wMinute << '.' << st.wSecond << '.' << st.wMilliseconds << '\n';*/
	for (short i = 0; i < 100; i++)
	{
		prevtime = GetTickCount();
		for (short j = 0; v[j] != 0; j++)
			cout << v[j];
		cout << "\n";
		times.push_back(GetTickCount() - prevtime);
	}
	for (short i = 0; i < int(times.size()); i++)
		sum = sum + times[i];
	int avg_time = sum / times.size();
	cout << "\n";
	cout << "average execution time: " << avg_time << "\n";
	/*GetSystemTime(&st);
	cout << st.wMinute << '.' << st.wSecond << '.' << st.wMilliseconds << '\n';*/
}

void ptrs(char v[])
{
int prevtime = 0;
int sum = 0;
vector <int> times;
	for (short i = 0; i < 100; i++)
	{
		prevtime = GetTickCount();
		for (char* p = v; *p != 0; p++) //приращение указателя перемещает нас на следующий адрес памяти. А все элементы одного массива в памяти располагаются рядом
			cout << *p;
		cout << "\n";
		times.push_back(GetTickCount() - prevtime);
	}
	for (short i = 0; i < int(times.size()); i++)
		sum = sum + times[i];
	int avg_time = sum / times.size();
	cout << "\n";
	cout << "average execution time: " << avg_time << "\n";

}


int main()
{
char test;
	ind(v); //оба метода выполняют одни и те же операции. Определить временные рамки не представляется возможным, тк слишком мала трудоёмкость операции. 
	cout << "\n"; //учебник говорит, что преобразовывается они в одинаковый машинный код. Однако, в имеющемся компиляторе, в среднем, по индексам выполняется дольше
	ptrs(v);    //претензия сельского борова о том, что я не слежу за памятью, косвенно подтверждает теорию о том, что по указателям будет быстрее
	cin >> test;
    return 0;
}

