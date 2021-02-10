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
  CHECK_SET,
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

void PrintErr(ERR_STATUS status) {
  switch (status) {
  case NO_OPEN_QUOTE:
    cout << "ERROR: No open quote" << endl;
    break;
  case NO_CLOSE_QUOTE:
    cout << "ERROR: No close quote" << endl;
    break;
  case INCORRECT_ARG:
    cout << "ERROR: Probem with input arguments (perhaps using bad symbols)" << endl;
    break;
  case TOO_LONG:
    cout << "ERROR: Argument is too long" << endl;
    break;
  case ERROR_SAME_NAME:
    cout << "ERROR: the set with this name already exist" << endl;
    break;
  case NOT_FOUND_SET:
    cout << "ERROR: the set with this name does not exist" << endl;
    break;
  case NOT_FOUND_EL:
    cout << "ERROR: the elem with this name does not exist in the set which name you entered" << endl;
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


void Process() {
  string input;
  string comand;
  string setName;
  string elemName;
  ERR_STATUS status = OK;
  univ_t* univ;
  int card = 0;
  decltype(input.size()) index;

  univ = InitUniv();

  while (getline(cin, input)) {
    for (index = 0; index != input.size() && !isspace(input[index]); ++index)
      comand += input[index];

    switch (Operator(comand))
    {
    case CREATE:
      status = InpGetArg(&setName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetCreate(setName, univ);
      if (status != OK) 
        PrintErr(status);
      break;

    case DELETE:
      status = InpGetArg(&setName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetDelete(setName, univ);
      if (status != OK)
        PrintErr(status);
      break;

    case CARDINALITY:
      status = InpGetArg(&setName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetCardinality(setName, univ, &card);
      if (status != OK)
        PrintErr(status);
      else
        std::cout << "Cardinality of " << setName << ": " << card << std::endl;
      break;

    case ADD_ELEM:
      status = InpGetTwoArgs(&elemName, &setName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = ElemAdd(elemName, setName, univ);
      if (status != OK)
        PrintErr(status);
      break;

    case DELETE_ELEM:
      status = InpGetTwoArgs(&elemName, &setName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = ElemDelete(elemName, setName, univ);
      if (status != OK)
        PrintErr(status);
      break;

    case SEARCH_ELEM:
      status = InpGetTwoArgs(&elemName, &setName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = ElemSearch(elemName, setName, univ);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      std::cout << "Element succesfully found" << std::endl;
      break;

    /*case UNION:

    case INTERSECTION:

    case DIFF:

    case SYMDIFF:

    case INCLUSION:*/

    case CHECK_SET:
      status = InpGetArg(&setName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetPrint(setName, univ);
      if (status != OK)
        PrintErr(status);
      break;

    case CHECK_SET_LIST:
      status = PrintSetList(univ);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      break;

    default:
      cout << "ERROR: wrong comand name" << endl;
      break;
    }

    comand = "";
    setName = "";
    elemName = "";
  }

  DeleteUniv(univ);

  return;
}