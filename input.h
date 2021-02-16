/*
* Library for correct input
*/

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <string>
#include "error.h"

#define MAX_LEN 80

ERR_STATUS InpGetArg(std::string* arg, std::wstring input, decltype(input.size())* index);
ERR_STATUS InpGetTwoArgs(std::string* arg1, std::string* arg2, std::wstring input, decltype(input.size())* index);
ERR_STATUS InpGetThreeArgs(std::string* arg1, std::string* arg2, std::string* arg3, std::wstring input, decltype(input.size())* index);

ERR_STATUS Help();

//ERR_STATUS InpCheckArg(wchar_t symb);

#endif /*INPUT_H*/