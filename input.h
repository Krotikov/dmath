#pragma once

#ifndef INPUT_H
#define INPUT_H

#include "error.h"

#define MAX 4294967295
#define BORD 429496729

//ERR_STATUS CheckArg(const unsigned num, const char symb);

ERR_STATUS Help();

ERR_STATUS ReadTwoArgs(unsigned& arg1, unsigned& arg2, size_t& index, const std::wstring& input);

ERR_STATUS ReadArg(unsigned& arg, size_t& index, const std::wstring& input);

#endif /*INPUT_H*/