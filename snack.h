#pragma once
#include <string>
using namespace std;

namespace wending_machine
{
	const short NUMBER_OF_SNACKS = 5;
	enum SnackType
	{
		ST_NODATA = 0,
		ST_PEANUTS = 100,
		ST_CHEESE = 120,
		SMALL_CHIPS = 70,
		BIG_CHIPS = 130,
		DRIED_FISH = 30
	};
	enum Calorie
	{
		C_NODATA = 0,
		C_PEANUTS = 6,
		C_CHEESE = 4,
		CHIPS = 5,
		FISH = 3
	};
	struct SnackInfo
	{
		short _id;
		string _name;
		short _cost;
		SnackType _type;
		Calorie _cal;
		SnackInfo();
		string ToString();
	};
	class Snack
	{
	public:
		Snack();
		Snack(short id);
		SnackInfo GetSnackInfo() const;
		string ToString();
		void FillSnackById(short id);

	private:
		SnackInfo _info;
		Calorie CalculateCalorie(SnackType type) const;
		void SetInfo(SnackInfo info);
	};
}