#include "error.h"
#include "input.h"
#include "combinatorics.h"

#pragma warning(disable: 4996)

using std::cout;
using std::endl;

void PrintErr(ERR_STATUS status) {
  switch (status) {
  case NO_OPEN_BR:
    cout << "ERROR: No open bracket" << endl;
    break;
  case NO_CLOSE_BR:
    cout << "ERROR: No close bracket" << endl;
    break;
  case INCORRECT_INPUT:
    cout << "ERROR: Probem with input (perhaps using bad symbols)" << endl;
    break;
  case INCORRECT_SYNTAX:
    cout << "ERROR: some problem with sintax (check help again - comand 'H')" << endl;
    break;
  case NO_COMA:
    cout << "ERROR: looks like you forgot to add coma" << endl;
    break;
  case TOOBIG_ARG:
    cout << "ERROR: the argument is too big for unsigned int" << endl;
    break;
  case WRONG_COMAND_NAME:
    cout << "ERROR: the comand with this name does not exist (check help('H'))" << endl;
    break;
  case NOT_CALC:
    cout << "ERROR: the value can't be calculate in 32-bit numbers" << endl;
    break;
  case EMPTY_STR:
    cout << "ERROR: there is no input" << endl;
    break;
  case ERROR:
    cout << "ERROR: does not classified this error" << endl;
    break;
  default:
    cout << "ERROR: Forgot to add new case" << endl;
    break;
  }

  return;
}


int main() {
  std::wstring input;
  char oper = '1';
  size_t index;
 

  do {
    input = L"";
    if (!getline(std::wcin, input)) {
      cout << "You entered ctrl+z, have a nice day" << endl;
      return OK;
    }

    if (input.empty() == true) {
      PrintErr(EMPTY_STR);
      continue;
    }

    unsigned arg1 = 0;
    unsigned arg2 = 0;
    unsigned res = 0;
    ERR_STATUS status = OK;
    index = 0;

    if (input[index] > 255) {
      PrintErr(WRONG_COMAND_NAME);
      continue;
    }
    oper = (char)input[index];
    ++index;

    if (oper == 'U' || oper == 'A' || oper == 'C' || oper == 'S') {
      status = ReadTwoArgs(arg1, arg2, index, input);
      if (status != OK) {
        PrintErr(status);
        continue;
      }
      switch (oper) {
      case 'U':
        status = U(arg1, arg2, res);
        if (status != OK) {
          PrintErr(status);
          break;
        }
        cout << "Res: " << res << endl;
        break;
      case 'A':
        status = A(arg1, arg2, res);
        if (status != OK) {
          PrintErr(status);
          break;
        }
        cout << "Res: " << res << endl;
        break;
      case 'C':
        status = C(arg1, arg2, res);
        if (status != OK) {
          PrintErr(status);
          break;
        }
        cout << "Res: " << res << endl;
        break;
      case 'S':
        status = S(arg1, arg2, res);
        if (status != OK) {
          PrintErr(status);
          break;
        }
        cout << "Res: " << res << endl;
        break;
      }

    }
    else if (oper == 'P' || oper == 'B') {
      status = ReadArg(arg1, index, input);
      if (status != OK) {
        PrintErr(status);
        continue;
      }
      switch (oper) {
      case 'P':
        status = P(arg1, res);
        if (status != OK) {
          PrintErr(status);
          break;
        }
        cout << "Res: " << res << endl;
        break;
      case 'B':
        status = B(arg1, res);
        if (status != OK) {
          PrintErr(status);
          break;
        }
        cout << "Res: " << res << endl;
        break;
      }
    }
    else if (oper == 'Q')
      return OK;
    else if (oper == 'H') 
      Help();
    else
      PrintErr(WRONG_COMAND_NAME);

  } while (oper != 'Q'); //will be useless

  return OK;
}