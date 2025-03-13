#include "snack.h";
#include <iostream>
using namespace std;

namespace wending_machine
{
	Snack::Snack()
	{
		//_info = SnackInfo();
	}

	Snack::Snack(short id)
	{
		FillSnackById(id);
	}


	void Snack::FillSnackById(short id)
	{
		_info._id = id;
		switch (id)
		{
		case 1:
			_info._type = ST_PEANUTS;
			_info._name = "Соленый арахис";
			_info._cost = 90;
			break;
		case 2:
			_info._type = ST_CHEESE;
			_info._name = "Копченый сыр";
			_info._cost = 123;
			break;
		case 3:
			_info._type = SMALL_CHIPS;
			_info._name = "Чипсы (мал.)";
			_info._cost = 79;
			break;
		case 4:
			_info._type = BIG_CHIPS;
			_info._name = "Чипсы (бол.)";
			_info._cost = 160;
			break;
		case 5:
			_info._type = DRIED_FISH;
			_info._name = "Сушеная рыба";
			_info._cost = 62;
			break;
		}
		_info._cal = CalculateCalorie(_info._type);
	}
	/*short Snack::GetCost() const
	{
		return _info._cost;
	}

	short Snack::GetWeight() const
	{
		return _info._type;
	}

	int Snack::GetCalories() const
	{
		return _info._type * _info._cal;
	}

	SnackType Snack::GetSnackType() const
	{
		return _info._type;
	}*/

	SnackInfo Snack::GetSnackInfo() const
	{
		return _info;
	}

	Calorie Snack::CalculateCalorie(SnackType type) const
	{
		
		switch (_info._type)
		{
		case ST_PEANUTS:
			return C_PEANUTS;
			break;
		case DRIED_FISH:
			return FISH;
			break;
		case ST_CHEESE:
			return C_CHEESE;
			break;
		case SMALL_CHIPS:
			return CHIPS;
			break;
		case BIG_CHIPS:
			return CHIPS;
			break;
		}
		return C_NODATA;
	}

	void Snack::SetInfo(SnackInfo info)
	{
		_info._id = info._id;
		_info._name = info._name;
		_info._cal = info._cal;
		_info._cost = info._cost;
		_info._type = info._type;
	}

	/*short Snack::GetSnackId() const
	{
		return _info._id;
	}*/

	string Snack::ToString()
	{
		string output = "";
		output += to_string(_info._id);
		output += ". " + _info._name;
		output += "; " + to_string(_info._cal * _info._type) + " ккал; ";
		output += "стоимость: " + to_string(_info._cost);
		output += " кред.";
		return output;
	}

	string SnackInfo::ToString()
	{
		return Snack(_id).ToString();
	}

	
	SnackInfo::SnackInfo()
	{
		_type = ST_NODATA;
		_cal = C_NODATA;
		_cost = 0;
		_id = 0;
		_name = "Неопределенный снэк";
	}

}



