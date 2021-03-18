#include "combinatorics.h"

ERR_STATUS U(const unsigned m, const unsigned n, unsigned& res) {
  if (n > m) {
    res = 0;
    return OK;
  }

  res = 1;
  unsigned max = MAX;
  for (unsigned i = 0; i < n; ++i) {
    unsigned mult = max / res;
    unsigned tmp = m - i;
    if(mult >= tmp)
      res *= (m - i);

    return NOT_CALC;
  }
  return OK;
}

ERR_STATUS A(const unsigned m, const unsigned n, unsigned& res) {
  res = 1;
  unsigned max = MAX;
  for (unsigned i = 0; i < n; ++i) {
    unsigned mult = max / res;
    if (mult >= m)
      res *= m;

    return NOT_CALC;
  }
  return OK;
}

ERR_STATUS P(const unsigned n, unsigned& res) {
  if (n > 12)
    return NOT_CALC;
  
  res = 1;
  for (unsigned i = 1; i <= n; ++i)
    res *= i;

  return OK;
}

ERR_STATUS C(const unsigned m, const unsigned n, unsigned& res) {
  if (n == 1 || m == (n + 1)) {
    res = m;
    return OK;
  }
  if (n > m) {
    res = 0;
    return OK;
  }
  if (n == m || n == 0) {
    res = 1;
    return OK;
  }
  unsigned tmp = n;
  if (n > m - n)
    tmp = m - n;

  ++tmp;
  unsigned* arr = new unsigned[tmp];
  unsigned max = MAX;
  for (unsigned i = 0; i < tmp; ++i)
    arr[i] = 1;

  for (unsigned i = 1; i < (m - tmp + 2); ++i) {
    for (unsigned j = 1; j < tmp; ++j) {
      if (arr[j - 1] > max - arr[j])
        return NOT_CALC;
      arr[j] = arr[j] + arr[j - 1];
    }
  }

  res = arr[tmp - 1];
  delete[] arr;
  return OK;
}

ERR_STATUS S(const unsigned m, const unsigned n, unsigned& res) {
  if (m == n) {
    res = 1;
    return OK;
  }
  if (n == 0) {
    res = 0;
    return OK;
  }
  if (n > m) {
    res = 0;
    return OK;
  }
  if (n == 1) {
    res = 1;
    return OK;
  }

  unsigned tmp = n + 1;
  unsigned* arr = new unsigned[tmp];
  unsigned max = MAX;
  //arr[0] = 0;
  for (unsigned i = 1; i < tmp; ++i)
    arr[i] = 1;

  for (unsigned i = 2; i < (m - tmp + 3); ++i) {
    for (unsigned j = 2; j < tmp; ++j) {
      if (arr[j - 1] > max - arr[j])
        return NOT_CALC;
      arr[j] = j*arr[j] + arr[j - 1];
    }
  }

  res = arr[tmp - 1];
  delete[] arr;
  return OK;
}

ERR_STATUS B(const unsigned n, unsigned& res) {
  if (n == 0) {
    res = 1;
    return OK;
  }
  unsigned len = n + 1;
  unsigned* arr = new unsigned[len];
  unsigned max = MAX;
  arr[1] = 1;
  

  for (unsigned i = 2; i < len; ++i) {
    unsigned tmp = arr[1];
    arr[1] = arr[i - 1];
    for (unsigned j = 2; j <= i; ++j) {
      if (arr[j - 1] > max - tmp)
        return NOT_CALC;
      unsigned prev = arr[j];
      arr[j] = arr[j - 1] + tmp;
      tmp = prev;
    }
  }

  res = arr[len - 1];
  delete[] arr;
  return OK;
}