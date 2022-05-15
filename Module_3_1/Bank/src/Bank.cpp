/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include "account.h"
#include "checkingAccount.h"
#include "savingAccount.h"


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
// Main
/*-------------------------------------------------------------------------------*/
int main()
{
    
    checkingAccount * myCA = 
        new checkingAccount(
            5,
            owner(
                string("Fulano"),
                string("Beltrano"),
                string("00.175.125.02"),
                string("123")
            ),
            1234
        );

    savingAccount * mySA = 
        new savingAccount(
            5,
            owner(
                string("Ciclano"),
                string("Beltrano"),
                string("00.175.342.01"),
                string("abc")
            ),
            1234
        );

    // accountList* accounts = loadAccountsFromJson(ACCOUNTS_SOURCE);
    // cout << "Bora Viado" << endl;
    // if (accounts == NULL) {
    //     cout << "Account file is missing!" << endl;
    // }
    // else {
        // cout << "Previous pointer :" <<  reinterpret_cast<void *>(accounts) << endl;  
        // accounts->appendAccount(
        //     bankAccount::account(
        //         5,
        //         owner::owner(
        //             string("ZezinhAAA"),
        //             string("Viadinho"),
        //             string("00.175.125.02")
        //         ),
        //         1234
        //     )
        // );
        
        // for (unsigned int i = 0; i < accountList::getNumberOfAccounts(); i++) {
        //     owner::owner AccountOwner = accounts->List[i]->getOwner();
        //     float balance = accounts->List[i]->getBalance();
        //     cout << AccountOwner.getFistName() << " : " << balance << endl;
        // }
    //    cout << "Number of Accounts :" << bankAccount::accountList::getNumberOfAccounts() << endl; 
    //    bankAccount::saveAccountsOnJson (ACCOUNTS_OUTPUT, accounts);
    // }

    return 0;
}