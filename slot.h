#pragma once
#include "snack.h"
#include "wallet.h"
namespace wending_machine
{
	class Slot
	{
	public:
		Slot(short size, short snackId);
		Slot();
		~Slot();

		bool GetNextSnack(Wallet* wallet);
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
