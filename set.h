/*
* Library for correct input
*/
#ifndef SET_H
#define SET_H
#include <iostream>
#include <string>

typedef struct elem_t {
  std::string str;
  elem_t* next;
}elem_t;

typedef struct {
  elem_t head;
}set_t;






#endif /*SET_H*/