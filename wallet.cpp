#include "wallet.h"

namespace wending_machine
{
	Wallet::Wallet(int credits)
	{
		_credits = credits;
	}

	void Wallet::AddCredits(int sum)
	{
		_credits += sum;
	}

	bool Wallet::DrawCredits(int sum)
	{
		if (sum > _credits)
		{
			return false;
		}
		AddCredits(-sum);
		return true;
	}

	int Wallet::GetBalance()
	{
		return _credits;
	}
}
