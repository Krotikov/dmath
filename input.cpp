#include "input.h"

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

ERR_STATUS CheckArg(const unsigned num, const wchar_t symb) { //symb - digit, num < MAX
  assert(num >= 0);
  assert(isdigit(symb));

  if (num < BORD)
    return OK;
  else if (num == BORD){
    if (symb == '0' || symb == '1' || symb == '2' || symb == '3' || symb == '4' || symb == '5')
      return OK;
    return TOOBIG_ARG;
  }
  else
    return TOOBIG_ARG;
}

ERR_STATUS ReadTwoArgs(unsigned& arg1, unsigned& arg2, size_t& index, const std::wstring& input) {
  int flag = 0;
  int flag2 = 0;  //when i will know how to makes it better I will do, but i do not know...

  arg1 = 0;
  arg2 = 0;

  //This for skip all spaces until '('
  for (; index != input.size(); ++index) {
    if (flag == 0)
      ++flag;
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (input[index] != '(')
      return NO_OPEN_BR;
    ++index; //skip '('
    break; //need to stop when '('
  }

  //This for skip all spaces between '(' and digit
  for (; index != input.size(); ++index) {
    if (flag == 1)
      ++flag;
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (!isdigit(input[index])) 
      return INCORRECT_SYNTAX;
    break; //need to not increase index
  }
  //This for reads first arg
  for (; index != input.size(); ++index) {
    if (flag == 2)
      ++flag;
    if (input[index] > 255) 
      return INCORRECT_INPUT;
    if (isdigit(input[index])) {
      if (CheckArg(arg1, input[index]) == OK) {  //--------------------------------
        arg1 = arg1 * 10 + (input[index] - '0');
        continue;
      }
      return TOOBIG_ARG;
    }
    break;
  }

  //This for is to skip all spaces between first arg and coma
  for (; index != input.size(); ++index) {
    if (flag == 3)
      ++flag;
    if (input[index] > 255) 
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (input[index] != ',')
      return NO_COMA;

    ++index; //skip coma
    break; //need to not increase index
  }

  //This for is to skip all spaces between coma and second arg
  for (; index != input.size(); ++index) {
    if (flag == 4)
      ++flag;
    if (input[index] > 255) 
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (!isdigit(input[index])) 
      return INCORRECT_SYNTAX;

    break; //not increase index
  }

  //This for is to read second arg
  for (; index != input.size(); ++index) {
    if (flag == 5)
      ++flag;
    if (input[index] > 255) 
      return INCORRECT_INPUT;
    if (isdigit(input[index])) {
      if (CheckArg(arg2, input[index]) == OK) {  //--------------------------------
        arg2 = arg2 * 10 + (input[index] - '0');
        continue;
      }
      return TOOBIG_ARG;
    }
    break;
  }

  //This for is to skip spaces between second arg and ')'
  for (; index != input.size(); ++index) {
    if (flag == 6)
      ++flag; //flag == 7 all neccessary thinks were done
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (input[index] != ')')
      return NO_CLOSE_BR;

    ++flag2; // detect ')'
    ++index; //skip ')'
    break; //need to not increase index

  }

  //This for is to check input after ')' and '\n'
  for (; index != input.size(); ++index) {
    if (flag == 7)
      ++flag;
    if (input[index] > 255) 
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (input[index] != '\n')
      return INCORRECT_SYNTAX;

    break; 
  }

  if (flag <= 6)
    return INCORRECT_SYNTAX;
  if (flag2 != 1)
    return NO_CLOSE_BR;

  return OK;
}

ERR_STATUS ReadArg(unsigned& arg, size_t& index, const std::wstring& input) {
  int flag = 0;
  int flag2 = 0;  //when i will know how to makes it better I will do, but i do not know...
  arg = 0;

  //This for skip all spaces until '('
  for (; index != input.size(); ++index) {
    if (flag == 0)
      ++flag;
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (input[index] != '(')
      return NO_OPEN_BR;
    ++index; //skip '('
    break; //need to stop when '('
  }

  //This for skip all spaces between '(' and digit
  for (; index != input.size(); ++index) {
    if (flag == 1)
      ++flag;
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (!isdigit(input[index]))
      return INCORRECT_SYNTAX;
    break; //need to not increase index
  }
  //This for reads arg
  for (; index != input.size(); ++index) {
    if (flag == 2)
      ++flag;
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isdigit(input[index])) {
      if (CheckArg(arg, input[index]) == OK) {  //--------------------------------
        arg = arg * 10 + (input[index] - '0');
        continue;
      }
      return TOOBIG_ARG;
    }
    break;
  }

  //This for is to skip all spaces between arg and ')'
  for (; index != input.size(); ++index) {
    if (flag == 3)
      ++flag; //flag == 4 (all correct)
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (input[index] != ')')
      return NO_CLOSE_BR;

    ++flag2; // detect ')'
    ++index; //skip ')'
    break; //need to not increase index
  }

  //This for is to check input after ')' and '\n'
  for (; index != input.size(); ++index) {
    if (flag == 4)
      ++flag;
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isspace(input[index]))
      continue;
    if (input[index] != '\n')
      return INCORRECT_SYNTAX;

    break;
  }

  if (flag <= 3)
    return INCORRECT_SYNTAX;
  if (flag2 != 1)
    return NO_CLOSE_BR;

  return OK;
}