/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include "account.h"


/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/
#define   ACCOUNTS_SOURCE    "./data/Accounts.json"
#define   ACCOUNTS_SOURCE_OUTPUT    "./data/AccountsOut.json"


using namespace std;


int main()
{

    bankAccount::account** Accounts = bankAccount::loadAccountsFromJson(ACCOUNTS_SOURCE);
    if (Accounts == NULL) {
        cout << "Account file is missing!" << endl;
    }
    else {
        Accounts = bankAccount::appendAccount(
                bankAccount::account(
                    5,
                    owner::owner("Zezinh", "Viadinho", "00.175.125.02"),
                    0.756
                ),
                Accounts
            );
        
        // for (unsigned int i = 0; i < bankAccount::account::getNumberOfAccounts(); i++) {
        //     owner::owner AccountOwner = Accounts[i]->getOwner();
        //     cout << AccountOwner.getFirstName() << endl;
        // }
       cout << "Number of Accounts :" << bankAccount::account::getNumberOfAccounts() << endl;
       bankAccount::saveAccountsOnJson (ACCOUNTS_SOURCE_OUTPUT, Accounts);
    }

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
