#ifndef INCLUDE_ACCOUNT_H
#define INCLUDE_ACCOUNT_H


/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <json.h>
#include "owner.h"

/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------*/
// Class Declaration
/*-------------------------------------------------------------------------------*/
class account
{	
	private:
		// static unsigned int numberOfAccounts;
		unsigned int accountId;
		owner ownerAccount;
	
	protected:
		float accountBalance;

	public:
		account(
			unsigned int inputAccountId,
			owner ownerAccount,
			float inputAccountBalance
		);
		virtual ~account();
		// static unsigned int getNumberOfAccounts();
		virtual void withdraw(float money) = 0;
		virtual void deposit(float money) = 0;
		unsigned int getAccountId(void) const;
		float getBalance(void) const;
		owner getOwner(void) const;
};

#endif //INCLUDE_ACCOUNT_H


