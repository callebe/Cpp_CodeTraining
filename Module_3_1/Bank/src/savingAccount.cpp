#include "savingAccount.h"

savingAccount::savingAccount(
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

savingAccount::~savingAccount()
{
}

void savingAccount::withdraw(float money)
{
    this->accountBalance -= money*(1+this->withdrawFee);
}

void savingAccount::deposit(float money)
{
    this->accountBalance += money;
}