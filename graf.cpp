#include "graf.h"

Graf::Graf(std::vector<std::wstring> edgeList) {
  size_ = edgeList.size();
  adjList_ = new node_t[size_];

  size_t ver1 = 0, ver2 = 0, cost = 0;

  for (auto& str : edgeList) {
    ReadArg(ver1, ver2, cost, str, size_);


  }

}