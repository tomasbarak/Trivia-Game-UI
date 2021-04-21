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
void loading(std::string username);
std::string sanitization(std::string to_sanitize);

#endif // FUNCTIONS_H_INCLUDED
