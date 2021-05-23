#include "graf.h"

#define INF -1
#define EMP -2

Graf::Graf(std::vector<std::wstring> edgeList, size_t n) {
  size_ = n*n;
  adjList_ = new ver_t[size_];
  status = OK;
  T = nullptr;
  P = nullptr;

  for (size_t i = 0; i < size_; ++i)
    adjList_[i].key = i;

  size_t ver1 = 0, ver2 = 0, cost = 0;

  for (auto& str : edgeList) {
    status = ReadArg(ver1, ver2, cost, str, size_);
    if (status != OK)
      return; //error 

    size_t v1 = ver1 - 1;
    size_t v2 = ver2 - 1;

    edge_t ed1 = { v1, cost };
    edge_t ed2 = { v2, cost };
    adjList_[v1].neighbors.push_back(ed2);
    adjList_[v2].neighbors.push_back(ed1);   
  }
}

void Graf::Init(ver_t s) {  //s = 1, however in program s = 0
  T = new int[size_];
  P = new size_t[size_];

  for (size_t i = 0; i < size_; ++i) {
    T[i] = INF;
    P[i] = 0;
  }
  T[s.key] = 0;
}

size_t Graf::W(size_t u, size_t v) {
  for (auto& w : adjList_[u].neighbors) {
    if (w.key == v)
      return w.cost;
  }

  return INF; //will never works
}

void Graf::Relax(ver_t s, edge_t v, ver_t u) { //T[u] != inf, W[u, v] != inf always.
  if (T[v.key] == INF || T[v.key] > T[u.key] + (int)W(u.key, v.key)) {
    T[v.key] = T[u.key] + (int)W(u.key, v.key);
    P[v.key] = u.key;
  }
}

STATUS Graf::ExtractMin(size_t* Q, ver_t& u) {
  //ver_t u;
  int min = INF;
  size_t minIndex = 0;
  STATUS flag = NOT_EMPTY;

  for (size_t i = 0; i < size_; ++i) {
    if (Q[i] == EMP)
      continue;

    if (min == INF && T[i] != INF) {
      min = T[i];
      u = adjList_[i];
      minIndex = i;
    }

    if (min != INF && T[i] != INF) {
      if (min > T[i]) {
        min = T[i];
        u = adjList_[i];
        minIndex = i;
      }
    }
  }

  if (min == INF) {
    flag = EMPTY;
    for (size_t i = 0; i < size_; ++i) {
      if (Q[i] != EMP) {
        flag = NOT_EMPTY;
        u = adjList_[i];
        minIndex = i;
      }
    }
  }

  Q[minIndex] = EMP;

  return flag;
}

STATUS Graf::Search(size_t* Q, edge_t& v) {
  for (size_t i = 0; i < size_; ++i)
    if (Q[i] == v.key)
      return YES;

  return NO;
}

void Graf::minpath() {
  ver_t s;
  s.key = 0; //because i decided to start from this point

  Init(s);

  size_t* Q = new size_t[size_];
  for (size_t i = 0; i < size_; ++i) {
    Q[i] = i;
  }

  STATUS flag = NOT_EMPTY;
  while (flag == NOT_EMPTY) {
    ver_t u;
    flag = ExtractMin(Q, u);

    if (T[u.key] == INF)
      break;

    for (edge_t& v : u.neighbors) {
      if (Search(Q, v) == YES)
        Relax(s, v, u);
    }
  }
}

std::string Graf::getMinPath() {
  std::string str("");
  if (P == nullptr)
    return str;

  size_t w = size_ - 1;
  str = "f";
  while (w != 0) {
    w = P[w];
    str += "-";
    if (w == 0) {
      str += "s";
      break;
    }
    str += std::to_string(w + 1);
  }

  //std::reverse(str.begin(), str.end());  because of problem with two digit numbers
  return str;
}