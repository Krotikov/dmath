#include "error.h"
#include "graf.h"

#define INF -1

using namespace std;

void PrintErr(ERR_STATUS status) {
  switch (status) {
  case NO_WAY:
    cout << "ERROR: not possible to find way from s to f in this graf" << endl;
    break;
  case INC_SIZE:
    cout << "ERROR: check the size of labirint it should be in [1, 20]" << endl;
    break;
  case EMPTY_GRAF:
    cout << "ERROR: the graf ypu entered is empty" << endl;
    break;
  case INC_GRAF:
    cout << "ERROR: the graf you entered has too many edges" << endl;
    break;
  case INCORRECT_INPUT:
    cout << "ERROR: the input file contains invalid characters" << endl;
    break;
  case NO_DASH:
    cout << "ERROR: there is some problem with dash in edge descrition in input file" << endl;
    break;
  case NO_SPACE:
    cout << "ERROR: there is some problem with dash in edge descrition in input file" << endl;
    break;
  case TOOBIG_ARG:
    cout << "ERROR: the value of vertex is too big" << endl;
    break;
  case TOOBIG_COST:
    cout << "ERROR: the value of cost is too big" << endl;
    break;
  case EMPTY_FILE:
    cout << "ERROR: the file is empty" << endl;
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

int main() {

  wfstream superfile("graf.txt"); //also available graf1.txt and graf2.txt
  vector<wstring> lineVec;
  ERR_STATUS status = OK;

  if (superfile.is_open()) {

    wstring str;
    getline(superfile, str);

    if (str.empty() == true) {
      PrintErr(EMPTY_FILE);
      return 0;
    }

    std::string::size_type sz;   // alias of size_t
    size_t n = stoi(str, &sz);  
    
    if (n < 1 || n > 20) {
      PrintErr(INC_SIZE);
      return 0;
    }

    wstring someline;

    while (getline(superfile, someline)){
      lineVec.push_back(someline);
    }
    
    if(lineVec.empty()) {
      PrintErr(EMPTY_GRAF);
      return 0;
    }
    else if (lineVec.size() > (n * n * (n * n - 1) / 2)) {
      PrintErr(INC_GRAF);
      return 0;
    }

    Graf graf(lineVec, n);
    if (graf.status != OK) {
      PrintErr(status);
      return 0;
    }

    graf.minpath();
    cout << graf.T[n * n - 1] << endl;

    if (graf.T[n * n - 1] == INF) {
      PrintErr(NO_WAY);
      return 0;
    }

    string path = graf.getMinPath();
    cout << "Path: " << path << endl;
  }
  else {
    cout << "ERROR: unable to open file" << endl;
  }

  return 0;
}

