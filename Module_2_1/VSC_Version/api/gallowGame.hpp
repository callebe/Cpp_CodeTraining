#include <string>
#include "gallows.hpp"
#include "randomWords.hpp"
#include <cstdlib>
#include <cstdio>
#include <iostream>

#ifndef __GALLOW_GAME_HPP_
#define __GALLOW_GAME_HPP_

void StartGame ( const unsigned int attemptLimit, const std::string dictionaryPath );
void printWelcome ( void );
void endGame ( void );
void mainLoop ( unsigned int attemptLimit );

#endif