
#include "account.h"

account::account(std::string inputFirstName, std::string inputLastName, std::string inputCpf)
{
	FirstName = inputFirstName;
	LastName = inputLastName;
	cpf  = inputCpf;
	accountBalance = 0;
}

account::account()
{
	accountId = 0;
	FirstName = "";
	LastName = "";
	cpf = "";
	accountBalance = 0;
}

void account::withdraw(float money)
{
	accountBalance -= money;
}

void account::deposit(float money)
{
	accountBalance += money;
}

float account::getBalance(void) const
{
	return accountBalance;
}

std::string account::getFirstName(void) const
{
	return FirstName;
}

std::string account::getLastName(void) const
{
	return LastName;
}

std::string account::getCpf(void) const
{
	return cpf;
}