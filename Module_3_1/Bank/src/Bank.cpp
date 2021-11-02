// Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Includes
#include <iostream>
#include <fstream>
#include <string>
#include <json.h>
#include <filesystem>
#include <iostream>

// Project includes
#include "account.h"

// Defines
#define   ACCOUNTS_SOURCE    "./data/Accounts.json"

using namespace std;
using json = nlohmann::json;

account* loadAccountsFromJson(unsigned int& numberOfAccounts);

int main()
{

    
    unsigned int numberOfAccounts;
    account* Accounts = loadAccountsFromJson(numberOfAccounts);
    
    cout << Accounts[0].getFirstName() << endl;
    
}

account* loadAccountsFromJson(unsigned int& numberOfAccounts)
{
    string line;
    string Input;
    account* Accounts = NULL;

    numberOfAccounts = 0;
    
    // Load string input from Json file
    std::ifstream inputFile;
    inputFile.open(ACCOUNTS_SOURCE, std::ios::binary | std::ios::in);
    if (!inputFile) {
        cout << "file doesn't exist";
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
    Accounts = new account[numberOfAccounts];

    for (unsigned int i = 0; i < numberOfAccounts; i++) {
        Accounts[i] = account(j["Accounts"][i]["accountId"],
                                j["Accounts"][i]["FirstName"],
                                j["Accounts"][i]["LastName"],
                                j["Accounts"][i]["cpf"],
                                j["Accounts"][i]["accountBalance"]);
    }

    return Accounts;
}

//bool loadXMLfromFile (const char* fileSourcePath, account &Conta )
//{
//
//    tinyxml2::XMLDocument Doc(true, tinyxml2::PRESERVE_WHITESPACE);
//    if (Doc.LoadFile(fileSourcePath) != tinyxml2::XML_SUCCESS) {
//        cout << "The Load process failed in try to load the Account data base!" << endl;
//        return 1;
//    }
//    //const char* title = doc.FirstChildElement("accounts")->FirstChildElement("account")->FirstChildElement("accountId")->GetText();
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
