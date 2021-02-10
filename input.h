/*
* Library for correct input
*/

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include "error.h"

#define MAX_LEN 80

ERR_STATUS InpGetArg(std::string* arg, std::string input, decltype(input.size())* index);

ERR_STATUS InpGetTwoArgs(std::string* arg1, std::string* arg2, std::string input, decltype(input.size())* index);

ERR_STATUS InpCheckArg(char symb);

#endif /*INPUT_H*/