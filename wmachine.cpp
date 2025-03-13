#include "wmachine.h"
#include <iostream>

namespace wending_machine
{
	WendingMachine::WendingMachine(short slotSize)
	{
		_slots = new Slot* [NUMBER_OF_SNACKS];
		for (short i = 0; i < NUMBER_OF_SNACKS; ++i)
		{
			_slots[i] = new Slot(slotSize, i + 1);
		}
		_slotSize = slotSize;
	}

	WendingMachine::~WendingMachine()
	{
		delete[] _slots;
	}

	string WendingMachine::DisplaySlots()
	{
		string output = "\n";
		SnackInfo* snackInfo = new SnackInfo[NUMBER_OF_SNACKS];
		short* snackQty = new short[NUMBER_OF_SNACKS];
		for (short j = 0; j < NUMBER_OF_SNACKS; ++j)
		{
			snackQty[j] = _slots[j]->GetRemainingSnacksQuantity();
			snackInfo[j] = _slots[j]->GetSnackInfo();
		}
		output += "Доступны слещдующие снэки:\n";
		output += DisplaySnackList(snackInfo, snackQty, NUMBER_OF_SNACKS);
		output += "\n\n"; 
		delete[] snackInfo;
		return output;
	}

	bool WendingMachine::GetSnack(short slotNum)
	{
		return _slots[slotNum - 1]->GetNextSnack();
	}

	string WendingMachine::DisplaySnackList(SnackInfo* list, short* snackQty, short size)
	{
		string output = "";
		for (short i = 0; i < NUMBER_OF_SNACKS; ++i)
		{
			if (list[i]._id && snackQty[i] != 0)
			{
				output += list[i].ToString();
				output += "; Осталось: " + to_string(snackQty[i]) + "\n";
			}
		}
		return output;
	}
}
