#pragma once

/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <json.h>


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
			std::string FirstName;
			std::string LastName;
			std::string cpf;
			float accountBalance;

		public:
			account(unsigned int inputAccountId,
				std::string inputFirstName,
				std::string inputLastName,
				std::string inputCpf,
				float inputAccountBalance);
			account();
			~account();
			static unsigned int getNumberOfAccounts();
			void withdraw(float money);
			void deposit(float money);
			float getBalance(void) const;
			std::string getFirstName(void) const;
			std::string getLastName(void) const;
			std::string getCpf(void) const;
	};


	/*-------------------------------------------------------------------------------*/
	// Function Declaration
	/*-------------------------------------------------------------------------------*/
	account** loadAccountsFromJson(const std::string fileName);

}


