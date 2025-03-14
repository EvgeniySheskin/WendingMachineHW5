#include "snack.h";
#include <iostream>
using namespace std;

namespace wending_machine
{
	Snack::Snack() 
	{	
	}

	Snack::Snack(SnackInfo info)
	{
		_info = info;
	}

	int Snack::GetCost() const
	{
		return _info._cost;
	}

	SnackInfo Snack::GetSnackInfo() const
	{
		return _info;
	}

	void Snack::SetInfo(SnackInfo info)
	{
		_info = info;
	}

	string Snack::ToString()
	{
		string output = "";
		output += _info._name;
		output += "; " + to_string(_info._calories) + " ккал; ";
		output += "стоимость: " + to_string(_info._cost);
		output += " кред.";
		return output;
	}
	

	string SnackInfo::ToString()
	{
		return Snack(*this).ToString();
	}

	SnackInfo::SnackInfo()
	{
		_cost = 0;
		_calories = 0;
		_name = "Неопределенный снэк";
	}
	
}



