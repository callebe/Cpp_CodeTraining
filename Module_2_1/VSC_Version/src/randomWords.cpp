#include "randomWords.hpp"

using namespace std;

std::string generateSecretWord ( const std::string dictionaryPath )
{

    std::string secretWord;
    int DictionaryWordsNumber = 0;

    // Open file and read dictionary
    std::ifstream MyReadFile(dictionaryPath);
    while (getline (MyReadFile, secretWord)) {
        DictionaryWordsNumber++;
    }
    MyReadFile.close();

    // Get a randon position
    srand(time(NULL));
    int randDictionaryWord = (int)rand()%DictionaryWordsNumber;

    // Collectin the word from the randon position
    std::ifstream MyReadFileB(dictionaryPath);
    for(int i=0; i<randDictionaryWord; i++){
        getline (MyReadFileB, secretWord);
    }
    MyReadFileB.close();

    return secretWord;
}

bool checkDictionaryPath ( const std::string dictionaryPath )
{

    ifstream ifile;
    ifile.open(dictionaryPath);
    if(ifile) {
        return true;
    } else {
       return false;
    }
}