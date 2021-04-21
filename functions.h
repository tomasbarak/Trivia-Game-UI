#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

void createWelcomeScreen();

std::string sanitization(std::string to_sanitize);
std::vector <std::string> readStats(std::string userName, bool createUser);

#endif // FUNCTIONS_H_INCLUDED
