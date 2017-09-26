/*������� ������������������ �������� ����������� �����������  
��������� ��� (���, ��������). ��� � ������������ �����, ������������  
����������� ���������. �������� ����������� ����� ������ ��� ������ 
� ��������� �������. ��������� � �������� ����� � ������� ��� ���  
������� ���������� �����, ��� � ��� ���� ���� (��. �6.1.8). */
#include "stdafx.h"
#include "Chapter6_3.h"
#include <map>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

vector <string> PassedKeys;

bool KeyPassed(const string key) //������ ���������� ������, �.�. ����� �������� ����� ��������, ��� ��� �� ����
{
	for (auto it = PassedKeys.begin(); it != PassedKeys.end(); ++it)
		if ((*it) == key)
			return true;
	return false;
}

void Chapter6_3()
{ //�������� ����������� � �������� �������� �� �����
float tot_sum = 0;
string CurName;
float CurValue = 0;
multimap<string, float> Lst; //������� map �� ��������� ����� ��� ���������� "first" ��������
short KeyCount;
	for (short i = 1; i < 5; i++)
	{	
		cout << "Enter the pair " << i << " : \n";
		cin >> CurName >> CurValue;
		Lst.emplace(CurName, CurValue);
		
	}
	
	for (auto it = Lst.begin(); it != Lst.end(); ++it)
	{
		tot_sum += (*it).second;
		if (!KeyPassed((*it).first))
		{
			CurValue = 0;
			PassedKeys.push_back((*it).first);
			KeyCount = 0;
			for (auto ins_it = Lst.begin(); ins_it != Lst.end(); ++ins_it)
				if ((*ins_it).first == (*it).first)
				{
					CurValue += (*ins_it).second;
					KeyCount++;
				}
			cout << (*it).first << " sum: " << CurValue << "\n";
			cout << (*it).first << " avg: " << CurValue / KeyCount << "\n";
		}
	}
	cout << "total sum: " << tot_sum << "\n";
	cout << "total average: " << tot_sum / Lst.size() << "\n";
	
}