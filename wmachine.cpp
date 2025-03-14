#include "wmachine.h"
#include <iostream>

namespace wending_machine
{
	WendingMachine::WendingMachine(short slotSize, short slotsCount)
	{
		_slots = new Slot* [slotsCount];
		for (short i = 0; i < slotsCount; ++i)
		{
			_slots[i] = new Slot();
		}
		_slotSize = slotSize;
		_slotsNumber = slotsCount;
		_emptySlots = slotsCount;
		_activeSlots = 0;
	}

	WendingMachine::~WendingMachine()
	{
		delete[] _slots;
	}

	string WendingMachine::DisplaySlots()
	{
		string output = "\n";
		SnackInfo* snackInfo = new SnackInfo[_activeSlots];
		short* snackQty = new short[_activeSlots];
		for (short j = 0; j < _activeSlots; ++j)
		{
			snackQty[j] = _slots[j]->GetRemainingSnacksQuantity();
			snackInfo[j] = _slots[j]->GetSnackInfo();
		}
		output += "Доступны слещдующие снэки:\n";
		output += DisplaySnackList(snackInfo, snackQty, _activeSlots);
		output += "\n\n"; 
		delete[] snackInfo;
		return output;
	}

	bool WendingMachine::GetSnack(short slotNum, Wallet* wallet)
	{
		return _slots[slotNum - 1]->GetNextSnack(wallet);
	}

	bool WendingMachine::AddSlot(Slot* newSlot)
	{
		if (_emptySlots > 0)
		{
			_slots[_activeSlots++] = newSlot;
			_emptySlots--;

			return true;
		}
		else
		{
			return false;
		}
		
	}

	string WendingMachine::DisplaySnackList(SnackInfo* list, short* snackQty, short size)
	{
		string output = "";
		for (short i = 0; i < _activeSlots; ++i)
		{
			if (snackQty[i] != 0)
			{
				output += to_string(i + 1) + ". ";
				output += list[i].ToString();
				output += "; Осталось: " + to_string(snackQty[i]) + "\n";
			}
		}
		return output;
	}
}
