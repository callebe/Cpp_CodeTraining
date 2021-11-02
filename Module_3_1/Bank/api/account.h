#pragma once

#include <string>

class account {

	private :
		unsigned int accountId;
		std::string FirstName;
		std::string LastName;
		std::string cpf;
		float accountBalance;
	public :
		account(unsigned int inputAccountId, std::string inputFirstName, std::string inputLastName, std::string inputCpf, float inputAccountBalance);
		account();
		void withdraw(float money);
		void deposit(float money);
		float getBalance(void) const;
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getCpf(void) const;
};