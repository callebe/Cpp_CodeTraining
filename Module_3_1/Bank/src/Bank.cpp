/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include "account.h"


/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/
#define   ACCOUNTS_SOURCE    "./data/Accounts.json"

/*-------------------------------------------------------------------------------*/
// Namespace definition
/*-------------------------------------------------------------------------------*/
using namespace std;

/*-------------------------------------------------------------------------------*/
// Function
/*-------------------------------------------------------------------------------*/
int main()
{

    bankAccount::accountList* accounts = bankAccount::loadAccountsFromJson(ACCOUNTS_SOURCE);
    if (accounts == NULL) {
        cout << "Account file is missing!" << endl;
    }
    else {
        cout << "Previous pointer :" <<  reinterpret_cast<void *>(accounts) << endl;          
        bankAccount::appendAccount(
            bankAccount::account(
                    5,
                    owner::owner(
                        string("Zezinh"),
                        string("Viadinho"),
                        string("00.175.125.02")
                    ),
                    1234
                ),
            accounts
        );
        
        for (unsigned int i = 0; i < bankAccount::accountList::getNumberOfAccounts(); i++) {
            owner::owner AccountOwner = accounts->List[i]->getOwner();
            float balance = accounts->List[i]->getBalance();
            cout << AccountOwner.getFirstName() << " : " << balance << endl;
        }
       cout << "Number of Accounts :" << bankAccount::accountList::numberOfAccounts << endl; 
       bankAccount::saveAccountsOnJson (ACCOUNTS_SOURCE, accounts);
    }

    return 0;
}
