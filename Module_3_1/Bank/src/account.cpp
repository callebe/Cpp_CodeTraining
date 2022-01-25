
#include "account.h"

/*-------------------------------------------------------------------------------*/
// account Class
/*-------------------------------------------------------------------------------*/

using json = nlohmann::json;

unsigned int bankAccount::account::numberOfAccounts = 0;

bankAccount::account::account(unsigned int accountId, owner::owner ownerAccount, float accountBalance):
    accountId(accountId),
    ownerAccount(ownerAccount),
    accountBalance(accountBalance)
{
    this->numberOfAccounts++;
    std::cout << "Criou: " << accountId << std::endl;
}

bankAccount::account::account()
{
    this->accountId = 0;
    this->accountBalance = 0;
}

bankAccount::account::~account()
{
    
    if(numberOfAccounts>0) numberOfAccounts--;
    std::cout << "Matou: " << accountId << std::endl;
}

unsigned int bankAccount::account::getNumberOfAccounts() {

    return numberOfAccounts;
}

void bankAccount::account::withdraw(float money)
{
    this->accountBalance -= money;
}

void bankAccount::account::deposit(float money)
{
    this->accountBalance += money;
}

unsigned int bankAccount::account::getAccountId(void) const
{
    return this->accountId;
}

float bankAccount::account::getBalance(void) const
{
	return this->accountBalance;
}

owner::owner bankAccount::account::getOwner(void) const
{
    return this->ownerAccount;
}

/*-------------------------------------------------------------------------------*/
// list account Class
/*-------------------------------------------------------------------------------*/
unsigned int bankAccount::accountList::numberOfAccounts = 0;

bankAccount::accountList::accountList(
        bankAccount::account** List,
        unsigned int listSize
    ):
    List(List)
{
    std::cout << "Hello" << std::endl;
    this->numberOfAccounts= listSize;
}

bankAccount::accountList::accountList()
{
    this->List = NULL;
    this->numberOfAccounts=0;
}

bankAccount::accountList::~accountList()
{
}

unsigned int bankAccount::accountList::getNumberOfAccounts()
{
    return numberOfAccounts;
}


/*-------------------------------------------------------------------------------*/
// Functions
/*-------------------------------------------------------------------------------*/
bankAccount::accountList* bankAccount::loadAccountsFromJson(const char* fileName)
{
    std::string line;
    std::string Input;
    account** Accounts = NULL;
    accountList* returnAccounts = NULL;
    unsigned int numberOfAccounts = 0;


    // Load string input from Json file
    std::ifstream inputFile;
    inputFile.open(fileName, std::ios::binary | std::ios::in);
    if (!inputFile) {
        return NULL;
    }

    while (getline(inputFile, line))
    {
        Input = Input + line + '\n';
    }
    inputFile.close();

    // Loading Json object return with the input file
    json j = json::parse(Input);
    numberOfAccounts = (unsigned int)j["Accounts"].size();
    Accounts = new account*[numberOfAccounts];

    
    for (unsigned int i = 0; i < numberOfAccounts; i++) {
        Accounts[i] = new account(
            j["Accounts"][i]["accountId"],
            owner::owner(
                j["Accounts"][i]["FirstName"],
                j["Accounts"][i]["LastName"],
                j["Accounts"][i]["cpf"]
            ),
            j["Accounts"][i]["accountBalance"]
        );
    }

    returnAccounts = new bankAccount::accountList(
        Accounts,
        numberOfAccounts
    );

    return returnAccounts;
}

void bankAccount::accountList::appendAccount(bankAccount::account newAccount)
{

    account** newAccounts = NULL;
    newAccounts = new account* [this->numberOfAccounts + 1];

    for (unsigned int i = 0; i < this->numberOfAccounts; i++) {
        newAccounts[i] = new bankAccount::account(
            this->List[i]->getAccountId(),
            this->List[i]->getOwner(),
            this->List[i]->getBalance()
        );
        delete this->List[i];
    }
    
    newAccounts[this->numberOfAccounts] = 
        new bankAccount::account(
            newAccount.getAccountId(),
            newAccount.getOwner(),
            newAccount.getBalance()
        );

    this->List = newAccounts;
    this->numberOfAccounts++;

    return;
}

int bankAccount::saveAccountsOnJson(const char* fileName, bankAccount::accountList* Accounts)
{
    json jsonFile;

    // Load string input from Json file
    std::ofstream outputFile(fileName);
    
    //Convert to json file
    for (unsigned int i = 0; i < bankAccount::account::getNumberOfAccounts(); i++) {
        jsonFile["Accounts"][i]["accountId"] = Accounts->List[i]->getAccountId();
        jsonFile["Accounts"][i]["FirstName"] = Accounts->List[i]->getOwner().getFirstName();
        jsonFile["Accounts"][i]["LastName"] = Accounts->List[i]->getOwner().getLastName();
        jsonFile["Accounts"][i]["cpf"] = Accounts->List[i]->getOwner().getCpf();
        jsonFile["Accounts"][i]["accountBalance"] = Accounts->List[i]->getBalance();
    }
    outputFile << std::setw(4) << jsonFile << std::endl;

    return 0;
}