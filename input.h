#ifndef INPUT_H
#define INPUT_H

#include "error.h"
#include <assert.h>

#define MAX 4294967295
#define BORD 429496729

ERR_STATUS ReadArg(size_t& ver1, size_t& ver2, size_t& cost, const std::wstring& input, size_t size);

#endif /*INPUT_H*/