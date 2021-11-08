
#include "account.h"

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

bankAccount::account** bankAccount::loadAccountsFromJson(const std::string fileName)
{
    std::string line;
    std::string Input;
    account** Accounts = NULL;
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
        Accounts[i] = new account(j["Accounts"][i]["accountId"],
                                  owner::owner(j["Accounts"][i]["FirstName"], j["Accounts"][i]["LastName"], j["Accounts"][i]["cpf"]),
                                  j["Accounts"][i]["accountBalance"]
                                );
    }

    return Accounts;
}

bankAccount::account** bankAccount::appendAccount(bankAccount::account newAccount, bankAccount::account** Accounts)
{

    account** newAccounts = NULL;
    newAccounts = new account* [bankAccount::account::getNumberOfAccounts() + 1];

    for (unsigned int i = 0; i < bankAccount::account::getNumberOfAccounts(); i++) {
        newAccounts[i] = Accounts[i];
    }
    
    newAccounts[bankAccount::account::getNumberOfAccounts()] = new bankAccount::account(
                                                                        newAccount.getAccountId(),
                                                                        newAccount.getOwner(),
                                                                        newAccount.getBalance()
                                                                    );

    return newAccounts;
}

int bankAccount::saveAccountsOnJson(const std::string fileName, bankAccount::account** Accounts)
{
    json jsonFile;

    // Load string input from Json file
    std::ofstream outputFile(fileName);
    
    //Convert to json file
    for (unsigned int i = 0; i < bankAccount::account::getNumberOfAccounts(); i++) {
        jsonFile["Accounts"][i]["accountId"] = Accounts[i]->getAccountId();
        jsonFile["Accounts"][i]["FirstName"] = Accounts[i]->getOwner().getFirstName();
        jsonFile["Accounts"][i]["LastName"] = Accounts[i]->getOwner().getLastName();
        jsonFile["Accounts"][i]["cpf"] = Accounts[i]->getOwner().getCpf();
        jsonFile["Accounts"][i]["accountBalance"] = Accounts[i]->getBalance();
    }
    outputFile << std::setw(4) << jsonFile << std::endl;

    return 0;
}