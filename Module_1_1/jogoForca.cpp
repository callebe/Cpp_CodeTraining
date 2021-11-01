#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <cstdio>
#include <map>
#include <vector>

// Defines
#define ATTEMPTS_LIMIT        50
#define DICTIONARY_PTBR       "wordsPtBr.txt"

using namespace std;

class gallows{
    int hitCounter;
    string secretWord;
    map <char, bool> charIsHidden;
    vector < char > wrongGuess;
    boolean findInWrongGuessList ( char guess );
    public:
        gallows( string input );
        string printGallow( void );
        boolean checkTip( char tips );
        string printSecretWord ( void );
        int getHitCounter ( void );
        string getWrongGuess ( void );
};

gallows::gallows(string input){

    hitCounter = input.length();
    secretWord = input;
    for(unsigned int i=0; i<input.length(); i++){
        charIsHidden[input[i]] = true;
    }
}

string gallows::printGallow( void ){

    string output;
    for(char letter : secretWord){
        if (charIsHidden[letter]){
            output = output + "  _";
        }
        else{
            output = output + "  " + letter;
        }
    }
    return output;
}

boolean gallows::checkTip( char tip ){

    int hit = false;

    for(char letter : secretWord){
        if (tip == letter){
            hit = true;
            charIsHidden[letter] = false;
            hitCounter--;
        }
    }

    if(!hit){
        if(!gallows::findInWrongGuessList(tip)) wrongGuess.push_back(tip);
    }
    return hit;
}

boolean gallows::findInWrongGuessList ( char guess ){

    boolean founded = false;

    for(unsigned int i=0; i<wrongGuess.size() && !founded; i++){
        if(wrongGuess[i] == guess){
            founded = true;
        }
    }
    return founded;
}

int gallows::getHitCounter ( void ){

    return hitCounter;
}

string gallows::getWrongGuess ( void ){
    
    string out;
    for(char letter : wrongGuess){

        out = out + " " + letter;
    }
    return out;
}

void setConsoleOutput2UTF8 (){
    
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, NULL, _IOFBF, 1000);
}

string generateSecretWord(){

    string secretWord;
    int DictionaryWordsNumber = 0;
    
    // Open file and read dictionary
    ifstream MyReadFile(DICTIONARY_PTBR);
    while (getline (MyReadFile, secretWord)) {
        DictionaryWordsNumber++;
    }
    MyReadFile.close();
    
    // Get a randon position
    srand(time(NULL));
    int randDictionaryWord = (int)rand()%DictionaryWordsNumber;

    // Collectin the word from the randon position
    ifstream MyReadFileB(DICTIONARY_PTBR);
    for(int i=0; i<randDictionaryWord; i++){
        getline (MyReadFileB, secretWord);
    }
    MyReadFileB.close();
    
    return secretWord;
}


int main (void){

    gallows theGallow (generateSecretWord());
    char guess;
    
    setConsoleOutput2UTF8();
    
    cout << "==================================" << endl;
    cout << "=          Hanging Game          =" << endl;
    cout << "==================================" << endl;
    cout << "=                                 " << endl;
    cout << "=>> " << theGallow.printGallow()   << endl;

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