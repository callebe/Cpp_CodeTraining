/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include "account.h"


/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/
#define   ACCOUNTS_SOURCE    "./data/Accounts.json"
#define   ACCOUNTS_OUTPUT    "./data/AccountsOut.json"

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
        accounts->appendAccount(
            bankAccount::account(
                5,
                owner::owner(
                    string("ZezinhAAA"),
                    string("Viadinho"),
                    string("00.175.125.02")
                ),
                1234
            )
        );
        
        for (unsigned int i = 0; i < bankAccount::accountList::getNumberOfAccounts(); i++) {
            owner::owner AccountOwner = accounts->List[i]->getOwner();
            float balance = accounts->List[i]->getBalance();
            cout << AccountOwner.getFirstName() << " : " << balance << endl;
        }
       cout << "Number of Accounts :" << bankAccount::accountList::getNumberOfAccounts() << endl; 
       bankAccount::saveAccountsOnJson (ACCOUNTS_OUTPUT, accounts);
    }

    return 0;
}
