#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>

#ifndef __RANDOM_WORDS_HPP_
#define __RANDOM_WORDS_HPP_

namespace randomWords {

	std::string generateSecretWord(const std::string dictionaryPath);
	bool checkDictionaryPath(const std::string dictionaryPath);

}
#endif