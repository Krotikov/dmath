/*
* Library for correct input
*/

#ifndef ERROR_H
#define ERROR_H
#include <iostream>

typedef enum {
  OK = 0,
  ERROR,
  NO_OPEN_QUOTE,
  NO_CLOSE_QUOTE,
  INCORRECT_ARG
}ERR_STATUS;

#endif /*ERROR_H*/