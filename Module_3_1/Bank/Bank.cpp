// Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "account.h"
#include "tinyxml2.h"

#define   ACCOUNTS_SOURCE    "Accounts.xml"

using namespace std;

bool loadXMLfromFile(const char* fileSourcePath, account& Conta);

int main()
{
    
    account Conta;
    char file[] = ACCOUNTS_SOURCE;

    loadXMLfromFile(file, Conta);


    cout << "Hello World!\n" <<  endl;
    
}

bool loadXMLfromFile (const char* fileSourcePath, account &Conta )
{

    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(fileSourcePath) != tinyxml2::XML_SUCCESS) {
        cout << "The Load process failed in try to load the Account data base!" << endl;
        return 1;
    }
    //const char* title = doc.FirstChildElement("accounts")->FirstChildElement("account")->FirstChildElement("accountId")->GetText();
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
