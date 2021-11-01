#include "randomWords.hpp"

inline bool fileExistsCheck (const std::string name) {

    std::ifstream f(name.c_str());
    return f.good();
}

bool generateSecretWord ( std::string *secretWord )
{

    int DictionaryWordsNumber = 0;
    
    //Check if the dictionary file exist
    if (!fileExistsCheck(DICTIONARY_PTBR)) return false;

    // Open file and read dictionary
    std::ifstream MyReadFile(DICTIONARY_PTBR);
    while (getline (MyReadFile, (*secretWord))) {
        DictionaryWordsNumber++;
    }
    MyReadFile.close();
    
    // Get a randon position
    srand(time(NULL));
    int randDictionaryWord = (int)rand()%DictionaryWordsNumber;

    // Collectin the word from the randon position
    std::ifstream MyReadFileB(DICTIONARY_PTBR);
    for(int i=0; i<randDictionaryWord; i++){
        getline (MyReadFileB, (*secretWord));
    }
    MyReadFileB.close();
    
    return true;
}