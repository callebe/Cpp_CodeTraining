#include "gallows.hpp"

gallows::gallow:: gallow(std::string input)
{

    hitCounter = input.length();
    secretWord = input;
    for(unsigned int i=0; i<input.length(); i++){
        charIsHidden[input[i]] = true;
    }
}

std::string gallows::gallow::printGallow( void )
{

    std::string output;
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

bool gallows::gallow::checkTip( char tip )
{

    int hit = false;

    for(char letter : secretWord){
        if (tip == letter){
            hit = true;
            charIsHidden[letter] = false;
            hitCounter--;
        }
    }

    if(!hit){
        if(!gallow::findInWrongGuessList(tip)) wrongGuess.push_back(tip);
    }
    return hit;
}

bool gallows::gallow::findInWrongGuessList ( char guess )
{

    bool founded = false;

    for(unsigned int i=0; i<wrongGuess.size() && !founded; i++){
        if(wrongGuess[i] == guess){
            founded = true;
        }
    }
    return founded;
}

int gallows::gallow::getHitCounter ( void )
{

    return hitCounter;
}

std::string gallows::gallow::getWrongGuess ( void )
{

    std::string out;
    for(char letter : wrongGuess){

        out = out + " " + letter;
    }
    return out;
}