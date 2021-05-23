#include "input.h"

ERR_STATUS CheckArg(const size_t num, const wchar_t symb, const size_t n) { //symb - digit, num < MAX
  assert(num >= 0);
  assert(isdigit(symb));

  size_t bord = n / 10;
  char adm = n % 10;

  if (num < bord)
    return OK;
  else if (num == bord) {
    if (symb - '0' < adm)
      return OK;
    return TOOBIG_ARG;
  }
  else
    return TOOBIG_ARG;
}

ERR_STATUS CheckCost(const unsigned num, const wchar_t symb) { //symb - digit, num < MAX
  assert(num >= 0);
  assert(isdigit(symb));

  if (num < BORD)
    return OK;
  else if (num == BORD) {
    if (symb == '0' || symb == '1' || symb == '2' || symb == '3' || symb == '4' || symb == '5')
      return OK;
    return TOOBIG_COST;
  }
  else
    return TOOBIG_COST;
}

ERR_STATUS ReadArg(size_t& ver1, size_t& ver2, size_t& cost, const std::wstring& input, size_t size) {
  ver1 = 0;
  ver2 = 0;
  cost = 0;

  int flagNum = 0;
  int index = 0;

  //this for reads ver1 value
  for (index = 0; index != input.size(); ++index) {
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isdigit(input[index])) {
      if (CheckArg(ver1, input[index], size) == OK) {  //--------------------------------
        ver1 = ver1 * 10 + (input[index] - '0');
        flagNum = 1;
        continue;
      }
      return TOOBIG_ARG;
    }
    if (input[index] == 's' && flagNum == 0) {
      ver1 = 1;
      ++index;
    }
    if (input[index] == 'f' && flagNum == 0) {
      ver1 = size;
      ++index;
    }
    if (input[index] != '-')
      return NO_DASH;
    ++index; //skip '-'
    break;
  }

  flagNum = 0;
  //this for reads ver2 value
  for (; index != input.size(); ++index) {

    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isdigit(input[index])) {
      if (CheckArg(ver2, input[index], size) == OK) {  //--------------------------------
        ver2 = ver2 * 10 + (input[index] - '0');
        flagNum = 1;
        continue;
      }
      return TOOBIG_ARG;
    }
    if (input[index] == 's' && flagNum == 0) {
      ver2 = 1;
      ++index;
    }
    if (input[index] == 'f' && flagNum == 0) {
      ver2 = size;
      ++index;
    }
    if (input[index] != ' ')
      return NO_SPACE;
    ++index; //skip ' '
    break;
  }

  //this for reads cost value
  for (; index != input.size(); ++index) {
    if (input[index] > 255)
      return INCORRECT_INPUT;
    if (isdigit(input[index])) {
      if (CheckCost(cost, input[index]) == OK) {  //--------------------------------
        cost = cost * 10 + (input[index] - '0');
        continue;
      }
      return TOOBIG_COST;
    }
    if (input[index] != '\n')
      return INCORRECT_INPUT;
    break;
  }

  return OK;
}
