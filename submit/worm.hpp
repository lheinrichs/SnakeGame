#ifndef WORM_HPP
#define WORM_HPP

#include "cell.hpp"

class Worm
{
public: 
  Worm(int row, int col);
  void insert(int row, int col);
  void remove();
  int size();
  Cell index(int index);


private:
  Cell * area;
  int _head;
  int _tail;
  int _size;
  int _poolSize;
};


#endif
