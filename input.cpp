#include "input.h"

ERR_STATUS InpCheckArg(char symb) {
  if (symb > 255)
    return ERROR;

  if (isprint(symb) == false)
    return ERROR;

  return OK;
}


ERR_STATUS InpGetArg(std::string* arg, std::string input, decltype(input.size())* index) {
  for (; *index < input.size() && isspace(input[*index]); ++(*index));

  if (input[*index] != '\"')
    return NO_OPEN_QUOTE;

  ++(*index);
  for (; *index < input.size() && input[*index] != '\"'; ++(*index)) {
    if(InpCheckArg(input[*index]) == ERROR)
      return INCORRECT_ARG;

    *arg += input[*index];
  }

  if (input[*index] != '\"')
    return NO_CLOSE_QUOTE;

  ++(*index);
  if (*index < input.size() && !isspace(input[*index]))
    return INCORRECT_ARG;

  return OK;
}




