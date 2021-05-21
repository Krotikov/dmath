#ifndef GRAF_H
#define GRAF_H

#include "error.h"
#include "input.h"

class node_t {
public:

  node_t() : ver(0), cost(0) 
  {};

  size_t ver;
  size_t cost;
  std::vector<int> neighbors;
};

class Graf {
public:

  Graf(std::vector<std::wstring> edgeList);

  Graf(Graf const& g);


private:
  size_t size_;
  node_t* adjList_;
};


#endif //GRAF_H