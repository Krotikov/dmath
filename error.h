#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

typedef enum {
  OK = 0,
  ERROR,
  INC_SIZE,
  NO_WAY,
  EMPTY_GRAF,
  INC_GRAF,
  INCORRECT_INPUT,
  INC_ARG,
  NO_DASH,
  NO_SPACE,
  TOOBIG_ARG,
  TOOBIG_COST,
  NO_SUCH_FILE,
  EMPTY_FILE

}ERR_STATUS;

#endif /*ERROR_H*/