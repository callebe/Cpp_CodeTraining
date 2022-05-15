#ifndef INCLUDE_CHECKING_ACCOUNT_H
#define INCLUDE_CHECKING_ACCOUNT_H

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
class checkingAccount final : public account
{
    private:
        void withdraw(float money) override;
        void deposit(float money) override;
        const float withdrawFee = 0.01;
        const float depositFee = 0.01;

    public:
        checkingAccount(
            unsigned int inputAccountId,
            owner ownerAccount,
            float inputAccountBalance
        );
        ~checkingAccount() override;
};

#endif // INCLUDE_CHECKING_ACCOUNT_H