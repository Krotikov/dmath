#include <iostream>
#include <string>
#include "input.h"
#include "process.h"

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
  
  Process();

  return 0;
}