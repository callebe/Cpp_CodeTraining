
#include "account.h"

using json = nlohmann::json;

unsigned int bankAccount::account::numberOfAccounts = 0;

bankAccount::account::account(unsigned int accountId, std::string FirstName, std::string LastName, std::string cpf, float accountBalance):
    accountId(accountId),
    FirstName(FirstName),
    LastName(LastName),
    cpf(cpf),
    accountBalance(accountBalance)
{
    this->numberOfAccounts++;
    std::cout << "Criou: " << accountId << std::endl;
}

bankAccount::account::account()
{
    this->accountId = 0;
    this->FirstName = "";
    this->LastName = "";
    this->cpf = "";
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

float bankAccount::account::getBalance(void) const
{
	return this->accountBalance;
}

std::string bankAccount::account::getFirstName(void) const
{
	return this->FirstName;
}

std::string bankAccount::account::getLastName(void) const
{
	return this->LastName;
}

std::string bankAccount::account::getCpf(void) const
{
	return this->cpf;
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
            j["Accounts"][i]["FirstName"],
            j["Accounts"][i]["LastName"],
            j["Accounts"][i]["cpf"],
            j["Accounts"][i]["accountBalance"]);
    }

    return Accounts;
}