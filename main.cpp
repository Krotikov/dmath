#include "process.h"

using std::string;
using std::cin;
using std::wcout;
using std::endl;


int wmain(int argc, wchar_t* argv[])
{
  //_setmode(_fileno(stdout), _O_U16TEXT);
  _setmode(_fileno(stdin), _O_U16TEXT);

  Process();

  return 0;
}