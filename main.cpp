#include <iostream>
#include <stdlib.h>
#include "wmachine.h"
using namespace std;
using namespace wending_machine;

int main()
{
	setlocale(LC_ALL, "");
	short ss = 0;
	cout << "������� ������� �����:\n";
	cin >> ss;
	system("cls");
	WendingMachine* wmachine = new WendingMachine(ss);
	cout << wmachine->DisplaySlots();
	char* slotNum = new char(0);
	bool* isSuccessful = new bool(true);
	bool* isOperational = new bool(true);
	bool* askingForConfirmation = new bool(true);
	char* confirm = new char(0);
	while (*isOperational)
	{
		cout << "������� ����� ����� ��� \'q\' ��� ������:\n";
		cin >> *slotNum;
		if (*slotNum == 'q')
		{
			cout << "������ ��� �������� ���!\n";
			break;
		}
		else
		{
			*slotNum -= '0';
		}
		if (*slotNum > NUMBER_OF_SNACKS)
		{
			cout << "������� ������������ ��������\n";
			continue;
		}
		*isSuccessful = wmachine->GetSnack(*slotNum);
		if (*isSuccessful)
		{
			*askingForConfirmation = true;
			cout << "��� ���� � �����. ������� �� ���-������ ���? y/n: ";
			while (*askingForConfirmation)
			{
				cin >> *confirm;
				if (*confirm == 'y')
				{
					*askingForConfirmation = false;
				}
				else if (*confirm == 'n')
				{
					cout << "�� ����� ������! ������ ��� �������� ���!\n";
					*askingForConfirmation = false;
					*isOperational = false;
				}
				else
				{
					cout << "������������ ����. ������� y/n:";
				}
			}
		}
		else 
		{
			cout << "� ���������, ��������� ������� ����� ����������, ���������� ������� ���-�� ���\n\n";
		}
		system("cls");
		cout << wmachine->DisplaySlots();
	}
	delete wmachine, slotNum, isSuccessful, isOperational, confirm, askingForConfirmation;

	return 0;
}