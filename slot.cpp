#include "slot.h"
#include "snack.h"
#include <iostream>

namespace wending_machine
{
	Slot::Slot(Snack* snacks, short size)
	{
		_snacks = snacks;
		_size = size;
		_position = size;
	}

	Slot::Slot(short size, short snackId)
	{
		_snacks = new Snack[size];
		for (short i = 0; i < size; ++i)
		{
			_snacks[i].FillSnackById(snackId);
		}
		_size = size;
		_position = size;
	}

	Slot::Slot()
	{
		_snacks = NULL;
		_size = 0;
		_position = 0;
	}

	Slot::~Slot()
	{
		delete[] _snacks;
	}

	short Slot::GetPosition() const
	{
		return _position;
	}

	bool Slot::GetNextSnack()
	{
		if (_position > 0)
		{
			_position--;
			return true;
		}
		else
		{
			return false;
		}
	}

	SnackInfo Slot::GetSnackInfo() const
	{
		if (_position > 0)
		{

			return _snacks[_position - 1].GetSnackInfo();
		}
		else
		{
			return SnackInfo();
		}
	}

	short Slot::GetRemainingSnacksQuantity() const
	{
		return GetPosition();
	}
	void Slot::FillSlot(short id)
	{
		
		for (short i = 0; i < _size; ++i)
		{
			_snacks[i].FillSnackById(id);
		}
	}
}
