#include "gallowGame.hpp"

// Global variable
static gallows::gallow *theGallow;

using namespace std;

void StartGame ( const unsigned int attemptLimit, const std::string dictionaryPath )
{

    std::string SecretWord;

    if(randomWords::checkDictionaryPath(dictionaryPath)  ){
        SecretWord = randomWords::generateSecretWord(dictionaryPath);
        theGallow = new gallows::gallow ( SecretWord );
        printWelcome();
        mainLoop( attemptLimit );
        endGame();
    }
    else{
        cout << "The Dictionary are note accessible" << endl;
        cout << "Please provide a dictionary" << endl;
    }
}

void printWelcome ( void )
{

    cout << "==================================" << endl;
    cout << "=          Hanging Game          =" << endl;
    cout << "==================================" << endl;
    cout << "=                                 " << endl;
    cout << "=>> " << (*theGallow).printGallow()   << endl;
}

void endGame ( void )
{

    cout << endl;
    cout << endl;
    if((*theGallow).getHitCounter() > 0){
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
}

void mainLoop ( unsigned int attemptLimit )
{

    char guess;

    for(unsigned int attempts = 0; attempts<attemptLimit && (*theGallow).getHitCounter()>0; attempts++){

        cout << "= >>" << (*theGallow).getWrongGuess() << endl;
        cout << "= Give your guess (1 character):  " << endl;
        cout << "= >> ";
        cin  >> guess;

        if ((*theGallow).checkTip(guess)){
            cout << "= You hit one!                   =" << endl;
        }
        else{
            cout << "= One out!                       =" << endl;
        }
        cout << "=                                " << endl;
        cout << "=>> " << (*theGallow).printGallow()   << endl;
    }
}