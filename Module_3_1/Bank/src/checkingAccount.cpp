#include "checkingAccount.h"

checkingAccount::checkingAccount(
    unsigned int inputAccountId,
    owner ownerAccount,
    float inputAccountBalance
):
    account(
        inputAccountId,
        ownerAccount,
        inputAccountBalance
    )
{
}

checkingAccount::~checkingAccount()
{
}

void checkingAccount::withdraw(float money)
{
    this->accountBalance -= money*(1+this->withdrawFee);
}

void checkingAccount::deposit(float money)
{
    this->accountBalance += money;
}