//File: cell.cpp
//Author: Lauren Heinrichs
//Project: 5, worm game

#include "cell.hpp"

using namespace std;

Cell:: Cell()
{
  _row = -1;
  _col = -1;
}

Cell:: Cell(int row, int col)
{
  _row = row;
  _col = col;
}

Cell:: ~Cell()
{
}

int Cell:: getRow()
{
  return _row;
}

int Cell:: getCol()
{
  return _col;
}

void Cell:: setRow(int row)
{
  _row = row;
}

void Cell:: setCol(int col)
{
  _col = col;
}
