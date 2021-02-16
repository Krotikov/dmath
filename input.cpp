#include "input.h"

ERR_STATUS InpCheckArg(wchar_t symb) {
  if (symb > 255)
    return ERROR;

  if (isprint(symb) == false || symb == '_')
    return WRONG_SYMBOL;

  return OK;
}


ERR_STATUS InpGetArg(std::string* arg, std::wstring input, decltype(input.size())* index) {
  for (; *index < input.size() && isspace(input[*index]); ++(*index));

  if (input[*index] != '\"')
    return NO_OPEN_QUOTE;

  ++(*index);
  for (; *index < input.size() && input[*index] != '\"'; ++(*index)) {
    if(InpCheckArg(input[*index]) != OK)
      return INCORRECT_ARG;

    *arg += input[*index];
  }

  if (input[*index] != '\"')
    return NO_CLOSE_QUOTE;

  ++(*index);
  if (*index < input.size() && !isspace(input[*index]))
    return INCORRECT_SYN;

  if ((*arg).size() > MAX_LEN)
    return TOO_LONG;

  return OK;
}

ERR_STATUS InpGetTwoArgs(std::string* arg1, std::string* arg2, std::wstring input, decltype(input.size())* index) {
  ERR_STATUS status = OK;

  status = InpGetArg(arg1, input, index);
  if (status != OK)
    return status;

  status = InpGetArg(arg2, input, index);
  if (status != OK)
    return status;

  return OK;
}

ERR_STATUS InpGetThreeArgs(std::string* arg1, std::string* arg2, std::string* arg3, std::wstring input, decltype(input.size())* index) {
  ERR_STATUS status = OK;

  status = InpGetArg(arg1, input, index);
  if (status != OK)
    return status;

  status = InpGetArg(arg2, input, index);
  if (status != OK)
    return status;

  status = InpGetArg(arg3, input, index);
  if (status != OK)
    return status;

  return OK;
}

ERR_STATUS Help() {
  std::ifstream in("help.txt");
  const int size = 256;
  char line[size] = { "" };

  if (!in)
    return ERROR;

  while (!in.eof()) {
    in.getline(line, size);
    std::wcout << line << std::endl;
  }
  in.close();

  return OK;
}



