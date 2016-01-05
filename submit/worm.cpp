//File: worm.cpp
//Author: Lauren Heinrichs
//Project: 5, worm game
#include "worm.hpp"

using namespace std;

Worm:: Worm(int row, int col)
{
  _poolSize = (row - 2) * (col - 2);
  area = new Cell[_poolSize];
  _head = 0;
  _tail = 0;
  _size = 0;

}

void Worm:: insert(int row, int col)
{
  Cell cell = Cell(row, col);
  area[_head % _poolSize] = cell;
  _head++;
  _size++;
}

void Worm:: remove()
{
  _tail++;
  _size--;
}

Cell Worm:: index(int index)
{
  return area[(_tail + index) % _poolSize];
}


int Worm:: size()
{
  return _size;
}

