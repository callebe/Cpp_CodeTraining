#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>

#ifndef __GALLOWS_HPP_
#define __GALLOWS_HPP_

namespace gallows {
    
    class gallow {
        int hitCounter;
        std::string secretWord;
        std::map <char, bool> charIsHidden;
        std::vector < char > wrongGuess;
        bool findInWrongGuessList(char guess);
    public:
        gallow(std::string input);
        std::string printGallow(void);
        bool checkTip(char tips);
        int getHitCounter(void);
        std::string getWrongGuess(void);
    };

}

#endif


