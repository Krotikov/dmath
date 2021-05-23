#ifndef GRAF_H
#define GRAF_H

#include "error.h"
#include "input.h"

typedef enum {
  EMPTY = -10,
  NOT_EMPTY,
  YES,
  NO
}STATUS;

typedef struct {
  size_t key;
  size_t cost;
}edge_t;

typedef struct {
  size_t key;
  std::vector<edge_t> neighbors;
}ver_t;

class Graf {
public:

  Graf(std::vector<std::wstring> edgeList, size_t n);

  ~Graf() {
    delete[] T;
    delete[] P;
  }

  //Graf(Graf const& g);

  void Init(ver_t s);

  void Relax(ver_t s, edge_t v, ver_t u);

  size_t W(size_t u, size_t v);

  STATUS ExtractMin(size_t* Q, ver_t& u);

  STATUS Search(size_t* Q, edge_t& v);

  void minpath();

  std::string getMinPath(); //it will work after minpath()

  ERR_STATUS status;
  int* T;
  size_t* P;

private:
  size_t size_;
  ver_t* adjList_;
};


#endif //GRAF_H