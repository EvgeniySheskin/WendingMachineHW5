#pragma once
#include "snack.h"
namespace wending_machine
{
	class Slot
	{
	public:
		Slot(Snack* snacks, short size);
		Slot(short size, short snackId);
		Slot();
		~Slot();

		bool GetNextSnack();
		SnackInfo GetSnackInfo() const;
		short GetRemainingSnacksQuantity() const;
		void FillSlot(short id);


	private:
		Snack* _snacks;
		short _size;
		short _position;
		short GetPosition() const;
	};
}
