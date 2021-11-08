#pragma once

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


namespace bankAccount
{
	/*-------------------------------------------------------------------------------*/
	// Class Declaration
	/*-------------------------------------------------------------------------------*/
	class account {	

		private:
			static unsigned int numberOfAccounts;
			unsigned int accountId;
			owner::owner ownerAccount;
			float accountBalance;

		public:
			account(unsigned int inputAccountId,
				owner::owner ownerAccount,
				float inputAccountBalance);
			account();
			~account();
			static unsigned int getNumberOfAccounts();
			void withdraw(float money);
			void deposit(float money);
			unsigned int getAccountId(void) const;
			float getBalance(void) const;
			owner::owner getOwner(void) const;
	};


	/*-------------------------------------------------------------------------------*/
	// Function Declaration
	/*-------------------------------------------------------------------------------*/
	account** loadAccountsFromJson(const std::string fileName);
	int saveAccountsOnJson(const std::string fileName, bankAccount::account** Accounts);
	bankAccount::account** appendAccount(bankAccount::account newAccount, bankAccount::account** Accounts);

}


