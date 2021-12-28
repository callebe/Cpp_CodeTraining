#include <string>
#include "gallowGame.hpp"

// Defines
#define ATTEMPTS_LIMIT         50
#define DICTIONARY_PTBR       ".\\data\\wordsPtBr.txt"

int main (void){

    StartGame ( ATTEMPTS_LIMIT,  DICTIONARY_PTBR);

    return 0;
}