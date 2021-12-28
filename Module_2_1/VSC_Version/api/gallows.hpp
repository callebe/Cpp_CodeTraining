#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>

#ifndef __GALLOWS_HPP_
#define __GALLOWS_HPP_

class gallows{
    int hitCounter;
    std::string secretWord;
    std::map <char, bool> charIsHidden;
    std::vector < char > wrongGuess;
    bool findInWrongGuessList ( char guess );
    public:
        gallows( std::string input );
        std::string printGallow( void );
        bool checkTip( char tips );
        std::string printSecretWord ( void );
        int getHitCounter ( void );
        std::string getWrongGuess ( void );
};

#endif


