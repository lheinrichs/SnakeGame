//File: freePoo.cpp
//Author: Lauren Heinrichs
//Project: 5, worm game

#include "freePool.hpp"

using namespace std;

freePool:: freePool(int row, int col)
{
  lastIndex = 0;
  area = new Cell[(row - 2) * (col - 2)];
}

void freePool:: insert(int &index, int row, int col)
{
  index = lastIndex;
  Cell cell = Cell(row, col);
  area[lastIndex] = cell;
  lastIndex++;
}

void freePool:: remove(int &index)
{
  area[index] = area[lastIndex - 1];
  lastIndex--;
  index = -1;
}

int freePool:: size()
{
  return lastIndex;
}

Cell freePool:: index(int index)
{
  return area[index];
}
