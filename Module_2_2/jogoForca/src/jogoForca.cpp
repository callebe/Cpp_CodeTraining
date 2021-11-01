#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "gallows.hpp"
#include "randomWords.hpp"

// Defines
#define ATTEMPTS_LIMIT        50

using namespace std;

int main (void){

    
    char guess;
    string SecretWord;

    // Secret word Generator
    if (!generateSecretWord(&SecretWord)) {
        cout << "========================================" << endl;
        cout << "=  The Secret Word Generation Failed!  =" << endl;
        cout << "========================================" << endl;

        return 0;
    }
    
    // Gallow instatiation
    gallows theGallow(SecretWord);

    cout << "==================================" << endl;
    cout << "=          Hanging Game          =" << endl;
    cout << "==================================" << endl;
    cout << "=                                 " << endl;
    cout << "=>> " << theGallow.printGallow() << endl;

    for(int attempts = 0; attempts<ATTEMPTS_LIMIT && theGallow.getHitCounter()>0; attempts++){

        cout << "= >>" << theGallow.getWrongGuess() << endl;
        cout << "= Give your guess (1 character):  " << endl;
        cout << "= >> ";
        cin  >> guess;

        if (theGallow.checkTip(guess)){
            cout << "= You hit one!                   =" << endl;
        }
        else{
            cout << "= One out!                       =" << endl;
        }
        cout << "=                                " << endl;
        cout << "=>> " << theGallow.printGallow()   << endl;
    }

    cout << endl;
    cout << endl;
    if(theGallow.getHitCounter() > 0){
        cout << "==================================" << endl;
        cout << "=            YOU LOSE            =" << endl;
        cout << "==================================" << endl;
    }
    else{
        cout << "==================================" << endl;
        cout << "=            YOU WIN!!           =" << endl;
        cout << "==================================" << endl;
    }
    cout << endl;
    cout << endl;

    return 0;
}