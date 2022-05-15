#include "account.h"
#include "savingAccount.h"
#include "checkingAccount.h"

/*-------------------------------------------------------------------------------*/
// account Class
/*-------------------------------------------------------------------------------*/

account::account(unsigned int accountId, owner ownerAccount, float accountBalance):
    accountId(accountId),
    ownerAccount(ownerAccount),
    accountBalance(accountBalance)
{
    std::cout << "Criou: " << accountId << std::endl;
}

account::~account()
{
    std::cout << "Matou: " << accountId << std::endl;
}

// void account::withdraw(float money)
// {
//     this->accountBalance -= money;
// }

// void account::deposit(float money)
// {
//     this->accountBalance += money;
// }

unsigned int account::getAccountId(void) const
{
    return this->accountId;
}

float account::getBalance(void) const
{
	return this->accountBalance;
}

owner account::getOwner(void) const
{
    return this->ownerAccount;
}