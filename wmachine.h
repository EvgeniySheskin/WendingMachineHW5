#pragma once
#include "slot.h"
#include <string>
#include "wallet.h"
namespace wending_machine
{
	class WendingMachine
	{
	public:
		WendingMachine(short slotSize, short slotsCount);
		~WendingMachine();
		string DisplaySlots();
		bool GetSnack(short slotNum, Wallet* wallet);

		bool AddSlot(Slot* newSlot);

	private:
		short _slotSize;
		short _slotsNumber;
		short _emptySlots;
		short _activeSlots;
		Slot** _slots;
		string DisplaySnackList(SnackInfo* list, short* snackQty, short size);
	};
}
