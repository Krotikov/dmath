/*
* Library for correct input
*/

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include "error.h"

ERR_STATUS InpGetArg(std::string* arg, std::string input, decltype(input.size())* index);

ERR_STATUS InpCheckArg(char symb);

#endif /*INPUT_H*/