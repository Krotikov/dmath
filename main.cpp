#include <iostream>
#include <string>
#include "input.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

/*
create "set_name" //correct
create "sob@4|(a" //correct
create "$_$+-_-"  //correct
create "set"name" //error
create "set_name  //error
create set_name"  //error
*/

int main() {
  string input("create \"setname");
  string comand;
  string arg;
  ERR_STATUS status = OK;
  decltype(input.size()) index;

  for (index = 0; index != input.size() && !isspace(input[index]); ++index)
    comand += input[index];

  cout << comand << endl;
  status = InpGetArg(&arg, input, &index);
  switch (status) {
  case OK:
    cout << arg << endl;
    break;
  case NO_OPEN_QUOTE:
    cout << "No open quote" << endl;
    break;
  case NO_CLOSE_QUOTE:
    cout << "No close quote" << endl;
    break;
  case INCORRECT_ARG:
    cout << "Probem with input arguments" << endl;
    break;
  default:
    cout << "Forgot to add new case" << endl;
    break;
  }

  /*while (getline(cin, input)) {
    cout << input << endl;

    while()
    */

  return 0;
}