#pragma once
#include <string>
using namespace std;

namespace wending_machine
{
	//const short NUMBER_OF_SNACKS = 5;

	struct SnackInfo
	{
	public:
		string _name;
		short _cost;
		short _calories;
		SnackInfo();
		string ToString();
	};
	class Snack
	{
		
	public:
		Snack();
		Snack(SnackInfo info);
		SnackInfo GetSnackInfo() const;
		string ToString();
		//void FillSnackById();
		int GetCost() const;

	private:
		SnackInfo _info;
		void SetInfo(SnackInfo info);
	};
}