#include <iostream>
#include <stdlib.h>
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
			cout << "\nДо новых встреч! Желаем вам хорошего дня!\n";
			*askingForConfirmation = false;
			return false;
		}
		else
		{
			cout << "\nНекорректный ввод. Введите y/n: ";
		}
	}
	delete confirm, askingForConfirmation;

}

int main()
{
	setlocale(LC_ALL, "");
	
	short *ss = new short(0);
	int* credits = new int(0);
	char* slotNum = new char(0);
	bool* isSuccessful = new bool(true);
	bool* isOperational = new bool(true);

	cout << "Введите размеры слота: ";
	cin >> *ss;
	cout << endl;
	cout << "Введите сумму доступных кредитов: ";
	cin >> *credits;
	
	WendingMachine* wmachine = new WendingMachine(*ss);
	Wallet* wallet = new Wallet(*credits);
	delete ss, credits;

	system("cls");

	cout << wmachine->DisplaySlots();
	cout << "Ваш баланс: " + to_string(wallet->GetBalance()) + "\n\n";
	
	while (*isOperational)
	{
		system("cls");
		cout << wmachine->DisplaySlots();
		cout << "Ваш баланс: " + to_string(wallet->GetBalance()) + "\n\n";
		cout << "Введите номер слота или \'q\' для выхода:\n";
		cin >> *slotNum;
		if (*slotNum == 'q')
		{
			cout << "Желаем вам хорошего дня!\n";
			break;
		}
		else
		{
			*slotNum -= '0';
		}
		if (*slotNum > NUMBER_OF_SNACKS)
		{
			cout << "Введено некорректное значение\n";
			continue;
		}
		*isSuccessful = wmachine->GetSnack(*slotNum, wallet);
		if (wallet->GetBalance() < 0)
		{
			cout << "На вашем счете недостаточно средств. Пополните баланс и возвращайтесь!\n\n";
			break;
		}
		if (*isSuccessful)
		{
			if (!ConfirmationRequest("Ваш снэк в лотке. Желаете ли что-нибудь еще? y/n: "))
			{
				*isOperational = false;
			}
		}
		else
		{
			if (!ConfirmationRequest("На вашем счете недостаточно средств. Хотите выбрать другой снэк? y/n: "))
			{
				*isOperational = false;
			}
		}
		
	}
	delete wmachine, slotNum, isSuccessful, isOperational;

	return 0;
}