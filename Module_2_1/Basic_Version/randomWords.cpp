#include "randomWords.hpp"

std::string generateSecretWord ( void )
{

    std::string secretWord;
    int DictionaryWordsNumber = 0;
    
    // Open file and read dictionary
    std::ifstream MyReadFile(DICTIONARY_PTBR);
    while (getline (MyReadFile, secretWord)) {
        DictionaryWordsNumber++;
    }
    MyReadFile.close();
    
    // Get a randon position
    srand(time(NULL));
    int randDictionaryWord = (int)rand()%DictionaryWordsNumber;

    // Collectin the word from the randon position
    std::ifstream MyReadFileB(DICTIONARY_PTBR);
    for(int i=0; i<randDictionaryWord; i++){
        getline (MyReadFileB, secretWord);
    }
    MyReadFileB.close();
    
    return secretWord;
}