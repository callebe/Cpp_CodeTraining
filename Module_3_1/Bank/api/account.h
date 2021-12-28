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
			account(
				unsigned int inputAccountId,
				owner::owner ownerAccount,
				float inputAccountBalance
			);
			account();
			~account();
			static unsigned int getNumberOfAccounts();
			void withdraw(float money);
			void deposit(float money);
			unsigned int getAccountId(void) const;
			float getBalance(void) const;
			owner::owner getOwner(void) const;
	};

	class accountList {	

		private:
			

		public:
			bankAccount::account** List;
			static unsigned int numberOfAccounts;
			accountList(
				bankAccount::account** List,
				unsigned int listSize
			);
			accountList();
			~accountList();
			static unsigned int getNumberOfAccounts();
	};

	/*-------------------------------------------------------------------------------*/
	// Function Declaration
	/*-------------------------------------------------------------------------------*/
	bankAccount::accountList* loadAccountsFromJson(const char* fileName);
	int saveAccountsOnJson(const char* fileName, bankAccount::accountList* Accounts);
	void appendAccount(bankAccount::account newAccount, bankAccount::accountList* Accounts);

}


