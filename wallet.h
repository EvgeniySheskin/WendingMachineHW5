#pragma once

namespace wending_machine
{
	class Wallet
	{
	public:
		Wallet(int credits);
		void AddCredits(int sum);
		bool DrawCredits(int sum);
		int GetBalance();
		

	private:
		int _credits;

	};
}
