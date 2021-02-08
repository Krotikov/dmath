#include "process.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

typedef enum {
  WRONG_COMAND = -1,
  CREATE, 
  DELETE,
  CARDINALITY, 
  ADD_ELEM, 
  DELETE_ELEM, 
  SEARCH_ELEM,
  UNION,
  INTERSECTION,
  DIFF,
  SYMDIFF,
  INCLUSION,
  CHECK_SET_LIST,
  CHECK_SET
}COMANDS_T;

COMANDS_T Operator(string comand) {
  if (comand == "create")
    return CREATE;
  if (comand == "delete")
    return DELETE;
  if (comand == "cardinality")
    return CARDINALITY;
  if (comand == "addElem")
    return ADD_ELEM;
  if (comand == "deleteElem")
    return DELETE_ELEM;
  if (comand == "searchElem")
    return SEARCH_ELEM;
  if (comand == "union")
    return UNION;
  if (comand == "intersection")
    return INTERSECTION;
  if (comand == "diff")
    return DIFF;
  if (comand == "symDiff")
    return SYMDIFF;
  if (comand == "inclusion")
    return INCLUSION;
  if (comand == "checkSetList")
    return CHECK_SET_LIST;
  if (comand == "checkSet")
    return CHECK_SET;

  return WRONG_COMAND;
}


ERR_STATUS Process() {
  string input;
  string comand;
  string arg;
  ERR_STATUS status = OK;
  decltype(input.size()) index;


  while (getline(cin, input)) {
    for (index = 0; index != input.size() && !isspace(input[index]); ++index)
      comand += input[index];

    switch (Operator(comand))
    {
    case CREATE:
    case DELETE:
    case CARDINALITY:
    case ADD_ELEM:
    case DELETE_ELEM:
    case SEARCH_ELEM:
    case UNION:
    case INTERSECTION:
    case DIFF:
    case SYMDIFF:
    case INCLUSION:
    case CHECK_SET:
    case CHECK_SET_LIST:
    default:
      cout << "ERROR: wrong comand name" << endl;
      break;
    }
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
  }


  return OK;
}