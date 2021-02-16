/*
* Library for correct input
*/
#ifndef SET_H
#define SET_H

#include "input.h"

typedef struct elem_t {
  std::string elemName;
  elem_t* next;
  elem_t* prev;
}elem_t;

typedef struct set_t {
  std::string setName;
  elem_t* head;
  set_t* next;
  set_t* prev;
}set_t;

typedef struct {
  set_t* head;
}univ_t;

univ_t* InitUniv();
ERR_STATUS PrintSetList(univ_t* univ);
ERR_STATUS DeleteUniv(univ_t* univ);

ERR_STATUS SetCreate(std::string setName, univ_t* univ);
ERR_STATUS SetPrint(std::string setName, univ_t* univ);
ERR_STATUS SetDelete(std::string setName, univ_t* univ);
ERR_STATUS SetCardinality(std::string setName, univ_t* univ, int* card);

ERR_STATUS ElemAdd(std::string elemName, std::string setName, univ_t* univ);
ERR_STATUS ElemSearch(std::string elemName, std::string setName, univ_t* univ);
ERR_STATUS ElemDelete(std::string elemName, std::string setName, univ_t* univ);

ERR_STATUS SetUnion(std::string setName1, std::string setName2, std::string resName, univ_t* univ);
ERR_STATUS SetIntersection(std::string setName1, std::string setName2, std::string resName, univ_t* univ);
ERR_STATUS SetDiff(std::string setName1, std::string setName2, std::string resName, univ_t* univ);
ERR_STATUS SetSymDiff(std::string setName1, std::string setName2, std::string resName, univ_t* univ);
ERR_STATUS SetInclusion(std::string setName1, std::string setName2, univ_t* univ);


#endif /*SET_H*/