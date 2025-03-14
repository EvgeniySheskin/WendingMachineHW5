#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "wmachine.h"
#include "wallet.h"
using namespace std;
using namespace wending_machine;

bool ConfirmationRequest(string msg)
{
	bool* askingForConfirmation = new bool(true);
	char* confirm = new char(0);
	cout << msg;
	while (*askingForConfirmation)
	{
		cin >> *confirm;
		if (*confirm == 'y')
		{
			*askingForConfirmation = false;
		}
		else if (*confirm == 'n')
		{
			cout << "\n�� ����� ������! ������ ��� �������� ���!\n";
			*askingForConfirmation = false;
			return false;
		}
		else
		{
			cout << "\n������������ ����. ������� y/n: ";
		}
	}
	delete confirm, askingForConfirmation;

}

Snack* CreateSnackByUser(short num)
{
	SnackInfo* info = new SnackInfo();
	cout << "������� �������� ����� " + to_string(num) + ": ";
	cin >> info->_name;
	cout << "������� ��������� ����� " + to_string(num) + ": ";
	cin >> info->_cost;
	cout << "������� ������������ ����� " + to_string(num) + ": ";
	cin >> info->_calories;
	Snack* snack = new Snack(*info);
	delete info;
	return snack;
}

Snack* CreateSnack(string name, short calories, int cost)
{
	SnackInfo* info = new SnackInfo();
	info->_name = name;
	info->_cost = cost;
	info->_calories = calories;
	Snack* snack = new Snack(*info);
	delete info;
	return snack;
}

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	short *ss = new short(0);
	short* slots = new short(0);
	int* credits = new int(0);
	char* slotNum = new char(0);
	bool* isSuccessful = new bool(true);
	bool* isOperational = new bool(true);

	cout << "������� ����� ������ � ��������: ";
	cin >> *slots;
	cout << endl;
	cout << "������� ������� �����: ";
	cin >> *ss;
	cout << endl;
	cout << "������� ����� ��������� ��������: ";
	cin >> *credits;
	
	WendingMachine* wmachine = new WendingMachine(*ss, *slots);
	Wallet* wallet = new Wallet(*credits);
	

	for (short i = 0; i < *slots; i++)
	{
		Slot* slot = new Slot(*ss, *CreateSnackByUser(i + 1));
		wmachine->AddSlot(slot);
	}
	delete ss, credits;

	system("cls");

	cout << wmachine->DisplaySlots();
	cout << "��� ������: " + to_string(wallet->GetBalance()) + "\n\n";
	
	while (*isOperational)
	{
		system("cls");
		cout << wmachine->DisplaySlots();
		cout << "��� ������: " + to_string(wallet->GetBalance()) + "\n\n";
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
		if (*slotNum > *slots)
		{
			cout << "������� ������������ ��������\n";
			continue;
		}
		*isSuccessful = wmachine->GetSnack(*slotNum, wallet);
		if (wallet->GetBalance() < 0)
		{
			cout << "�� ����� ����� ������������ �������. ��������� ������ � �������������!\n\n";
			break;
		}
		if (*isSuccessful)
		{
			if (!ConfirmationRequest("��� ���� � �����. ������� �� ���-������ ���? y/n: "))
			{
				*isOperational = false;
			}
		}
		else
		{
			if (!ConfirmationRequest("�� ����� ����� ������������ �������. ������ ������� ������ ����? y/n: "))
			{
				*isOperational = false;
			}
		}
		
	}
	delete wmachine, slotNum, isSuccessful, isOperational, slots;

	return 0;
}