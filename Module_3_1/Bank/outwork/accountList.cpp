
/*-------------------------------------------------------------------------------*/
// Function
/*-------------------------------------------------------------------------------*/
unsigned int accountList::numberOfAccounts = 0;

accountList::accountList(
        account** List,
        unsigned int listSize
    ):
    List(List)
{
    std::cout << "Hello" << std::endl;
    this->numberOfAccounts= listSize;
}

accountList::accountList()
{
    this->List = NULL;
    this->numberOfAccounts=0;
}

accountList::~accountList()
{
}

unsigned int accountList::getNumberOfAccounts()
{
    return numberOfAccounts;
}

accountList* loadAccountsFromJson(const char* fileName)
{
    std::string line;
    std::string Input;
    // account** Accounts = NULL;
    savingAccount** Accounts = NULL;
    accountList* returnAccounts = NULL;
    unsigned int numberOfUsers = 0;


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
    numberOfUsers = (unsigned int)j["Accounts"].size();
    // Accounts = new account*[numberOfUsers];
    Accounts = new savingAccount*[numberOfUsers];

    
    for (unsigned int i = 0; i < numberOfUsers; i++) {
        // Loading a Saving Account
        if(j["Accounts"][i].contains("savingAccount")){
            Accounts[i] = new savingAccount(
                j["Accounts"][i]["accountId"],
                owner::owner(
                    j["Accounts"][i]["FirstName"],
                    j["Accounts"][i]["LastName"],
                    j["Accounts"][i]["cpf"]
                ),
                j["Accounts"][i]["accountBalance"]
            );
        }
        // Loading a CheckingAccount
        // if(j["Accounts"][i].contains("checkingAccount")){
        //     Accounts[i] = new checkingAccount(
        //         j["Accounts"][i]["accountId"],
        //         owner::owner(
        //             j["Accounts"][i]["FirstName"],
        //             j["Accounts"][i]["LastName"],
        //             j["Accounts"][i]["cpf"]
        //         ),
        //         j["Accounts"][i]["accountBalance"]
        //     );
        // }
        // Loading a bankEmployee
        // if(j["Accounts"][i].contains("bankEmployee")){
        //     Accounts[i] = new account(
        //         j["Accounts"][i]["accountId"],
        //         owner::owner(
        //             j["Accounts"][i]["FirstName"],
        //             j["Accounts"][i]["LastName"],
        //             j["Accounts"][i]["cpf"]
        //         ),
        //         j["Accounts"][i]["accountBalance"]
        //     );
        // }
    }

    // returnAccounts = new accountList(
    //     Accounts,
    //     numberOfUsers
    // );

    return returnAccounts;
}

void accountList::appendAccount(account newAccount)
{

    account** newAccounts = NULL;
    newAccounts = new account* [this->numberOfAccounts + 1];

    for (unsigned int i = 0; i < this->numberOfAccounts; i++) {
        newAccounts[i] = new account(
            this->List[i]->getAccountId(),
            this->List[i]->getOwner(),
            this->List[i]->getBalance()
        );
        delete this->List[i];
    }
    
    newAccounts[this->numberOfAccounts] = 
        new account(
            newAccount.getAccountId(),
            newAccount.getOwner(),
            newAccount.getBalance()
        );

    this->List = newAccounts;
    this->numberOfAccounts++;

    return;
}

int saveAccountsOnJson(const char* fileName, accountList* Accounts)
{
    json jsonFile;

    // Load string input from Json file
    std::ofstream outputFile(fileName);
    
    //Convert to json file
    for (unsigned int i = 0; i < account::getNumberOfAccounts(); i++) {
        jsonFile["Accounts"][i]["accountId"] = Accounts->List[i]->getAccountId();
        jsonFile["Accounts"][i]["accountBalance"] = Accounts->List[i]->getBalance();
        owner::owner accountOwner = Accounts->List[i]->getOwner();
        jsonFile["Accounts"][i]["FirstName"] = accountOwner.getFistName();
        jsonFile["Accounts"][i]["LastName"] = accountOwner.getLastName();
        jsonFile["Accounts"][i]["cpf"] = accountOwner.getCpf();
    }
    outputFile << std::setw(4) << jsonFile << std::endl;

    return 0;
}