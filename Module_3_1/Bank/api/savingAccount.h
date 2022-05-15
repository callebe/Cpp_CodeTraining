#ifndef INCLUDE_SAVINGACCOUNT_H
#define INCLUDE_SAVINGACCOUNT_H

/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include "account.h"

/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------*/
// Class Declaration
/*-------------------------------------------------------------------------------*/

class savingAccount final : public account
{
    private:
        void withdraw(float money) override;
        void deposit(float money) override;
        const float withdrawFee = 0.02;

    public:
        savingAccount(
            unsigned int inputAccountId,
            owner ownerAccount,
            float inputAccountBalance
        );
        ~savingAccount() override;
};

#endif // INCLUDE_SAVINGACCOUNT_H