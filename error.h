#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

typedef enum {
  OK = 0,
  ERROR,
  INCORRECT_SYNTAX, // absent of '(' or ',' or ')'
  INCORRECT_INPUT, //char > 255 (not allowed characters)
  NO_OPEN_BR,
  NO_CLOSE_BR,
  NO_COMA,
  TOOBIG_ARG,
  WRONG_COMAND_NAME, 
  NOT_CALC, 
  EMPTY_STR

}ERR_STATUS;

#endif /*ERROR_H*/