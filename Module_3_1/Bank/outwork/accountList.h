#ifndef __ACCOUNTLIST_H__
#define __ACCOUNTLIST_H__

/*-------------------------------------------------------------------------------*/
// Classes Declaration
/*-------------------------------------------------------------------------------*/
class accountList {	

	private:
		static unsigned int numberOfAccounts;

	public:
		account** List;
		accountList(
			account** List,
			unsigned int listSize
		);
		accountList();
		~accountList();
		static unsigned int getNumberOfAccounts();
		void appendAccount(account newAccount);
};

/*-------------------------------------------------------------------------------*/
// Function Declaration
/*-------------------------------------------------------------------------------*/
accountList* loadAccountsFromJson(const char* fileName);
int saveAccountsOnJson(const char* fileName, accountList* Accounts);

#endif // __ACCOUNTLIST_H__