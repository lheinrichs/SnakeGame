#ifndef CELL_HPP
#define CELL_HPP

class Cell
{
public:
  Cell();
  Cell(int row, int col);
  ~Cell();
  int getRow();
  int getCol();
  void setRow(int row);
  void setCol(int col);

private:
  int _row;
  int _col;

};

#endif
