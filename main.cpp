#include "error.h"
#include "graf.h"

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

  wfstream superfile("graf.txt");
  vector<wstring> lineVec;
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

    size_t ver1 = 0, ver2 = 0, cost = 0;

    for (auto& str : lineVec) {
      if (ReadArg(ver1, ver2, cost, str, 4) == OK) {
        cout << ver1 << " " << ver2 << " " << cost << endl;
        continue;
      }

      return 1;
    }

  }
  else {
    cout << "Unable to open file" << endl;
  }

  return 0;
}

