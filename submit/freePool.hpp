#ifndef FREEPOOL_HPP
#define FREEPOOL_HPP

#include "cell.hpp"

class freePool
{
public:
  freePool(int row, int col);
  void insert(int &index, int row, int col);
  void remove(int &index);
  int size();
  Cell index(int);

private:
  int lastIndex;
  Cell * area;

};

#endif
