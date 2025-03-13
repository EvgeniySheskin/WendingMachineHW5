#pragma once
#include "slot.h"
#include <string>
#include "wallet.h"
namespace wending_machine
{
	class WendingMachine
	{
	public:
		WendingMachine(short slotSize);
		~WendingMachine();
		string DisplaySlots();
		bool GetSnack(short slotNum, Wallet* wallet);

	private:
		short _slotSize;
		Slot** _slots;
		string DisplaySnackList(SnackInfo* list, short* snackQty, short size);
	};
}
