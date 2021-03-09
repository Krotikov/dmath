#include "process.h"

//using std::wstring;
using std::string;
using std::wcin;
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
  HELP
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
  if (comand == "help")
    return HELP;

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
  case ERROR_SAME_NAME_SET:
    cout << "ERROR: the set with this name already exist" << endl;
    break;
  case ERROR_SAME_NAME_ELEM:
    cout << "ERROR: the element with this name already exist" << endl;
    break;
  case NOT_FOUND_SET:
    cout << "ERROR: the set with this name does not exist" << endl;
    break;
  case NOT_FOUND_EL:
    cout << "ERROR: the elem with this name does not exist in the set which name you entered" << endl;
    break;
  case INCLUDE:
    cout << "TRUE" << endl;
    break;
  case NOT_INCLUDE:
    cout << "FALSE" << endl;
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
  //Main
  std::wstring input;
  string comand;
  univ_t* univ;
  decltype(input.size()) index;
  //For func
  string setName;
  string elemName;
  //For set operations
  string setName1;
  string setName2;
  string resName;
  //For set cardinality
  int card = 0;
  ERR_STATUS status = OK;

  univ = InitUniv();

  while (getline(wcin, input)) {
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

    case UNION:
      status = InpGetThreeArgs(&setName1, &setName2, &resName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetUnion(setName1, setName2, resName, univ);
      if (status != OK)
        PrintErr(status);
      break;

    case INTERSECTION:
      status = InpGetThreeArgs(&setName1, &setName2, &resName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetIntersection(setName1, setName2, resName, univ);
      if (status != OK)
        PrintErr(status);
      break;

    case DIFF:
      status = InpGetThreeArgs(&setName1, &setName2, &resName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetDiff(setName1, setName2, resName, univ);
      if (status != OK)
        PrintErr(status);
      break;

    case SYMDIFF:
      status = InpGetThreeArgs(&setName1, &setName2, &resName, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetSymDiff(setName1, setName2, resName, univ);
      if (status != OK)
        PrintErr(status);
      break;

    case INCLUSION:
      status = InpGetTwoArgs(&setName1, &setName2, input, &index);
      if (status != OK) {
        PrintErr(status);
        break;
      }
      status = SetInclusion(setName1, setName2, univ);
      if (status != OK)
        PrintErr(status);
      break;

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

    case HELP:
      status = Help();
      if (status != OK) {
        PrintErr(status);
        break;
      }
      break;

    default:
      cout << "ERROR: wrong comand name" << endl;
      break;
    }

    //free all strings
    comand = "";
    setName = "";
    elemName = "";
    setName1 = "";
    setName2 = "";
    resName = "";
  }

  DeleteUniv(univ);

  return;
}