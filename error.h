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
  INCORRECT_ARG,
  INCORRECT_SYN,
  WRONG_SYMBOL,
  TOO_LONG,
  ERROR_SAME_NAME, 
  NOT_FOUND_SET, 
  NOT_FOUND_EL, 
  NOT_INCLUDE, 
  INCLUDE
}ERR_STATUS;

#endif /*ERROR_H*/