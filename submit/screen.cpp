//File: screen.cpp // main function
//Author: Lauren Heinrichs
//Project: 5, worm game
#include <curses.h>
#include "getChar.hpp"
#include "cell.hpp"
#include "freePool.hpp"
#include "worm.hpp"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <time.h>

using namespace std;

void startup( void );
void done(int totalScore );

int main(int charc, char *argv[2])
{
  srand(time(NULL));
  int index = 0;
  int row = stoi(argv[1]);
  int column = stoi(argv[2]);

  if(charc != 3)
    {
      cout << "Not enough arguments" << endl;
      exit(1);
    }

  if(row < 9 || row > 25)
    {
      cout << "Invalid number of rows, please enter a number between 9 and 25" << endl;
      exit(1);
    }

  if(column < 9 || column > 80)
    {
      cout << "Invalid number of columns, please enter a number between 9 and 80" << endl;
      exit(1);
    }

  startup();
  mvaddstr(0, 0, "Worm");
  mvaddstr(0, column - 15,"Total Score: ");

  int ** grid = new int*[column];
  freePool * pool = new freePool(row, column);
  Worm * worm = new Worm(row, column);

  for(int i = 1; i < column; i++)
    {
      grid[i] = new int[row];
      for(int j = 1; j < row; j++)
	{
	  if(i == 1 || i == column - 1 || j == 1 || j == row - 1)
	    {
	      grid[i][j] = -1;
	      mvaddch(i, j, '*');
	    }
	  else
	    pool -> insert(grid[i][j], i, j);
	}
    }
  refresh();

  int wormLength = 1;
  int Row = row / 2;
  int Col = column / 2;
  int totalScore = 0;
  int munchie = (rand () % 9) + 1;
  Cell Munch = pool -> index(rand() % pool -> size());
  int munchRow = Munch.getRow();
  int munchCol = Munch.getCol();
  char c;

  mvaddstr( munchRow, munchCol, to_string(munchie).c_str());

  while(true)
    {
      totalScore = wormLength - 1;
      mvaddstr(0, column, to_string(totalScore).c_str());
      mvaddch(Row, Col, 'o');
      c = get_char();

      if(c == 'w') //up
	Row--;
      else if(c == 'a') //left
	Col--;
      else if(c == 'd') //right
	Col++;
      else if(c == 's') //down
	Row++;
      if(c != ' ' && grid[Row][Col] == - 1)
	done(totalScore);

      mvaddch(Row, Col, '@');

      worm -> insert(Row, Col);
      int endRow = pool -> index(pool -> size() - 1).getRow();
      int endCol = pool -> index(pool -> size() - 1).getCol();
      grid[endRow][endCol] = grid[Row][Col];
      pool -> remove(grid[Row][Col]);

      if(munchRow == Row && munchCol == Col)
	{
	  Cell Munch = pool -> index(rand() % pool -> size());
	  munchRow = Munch.getRow();
	  munchCol = Munch.getCol();
	  wormLength += munchie;
	  munchie = (rand() % 9) + 1;
	  mvaddstr(munchRow, munchCol,to_string(munchie).c_str());
	}

      if(worm -> size() > wormLength)
	{
	  int wormTailRow = worm -> index(0).getRow();
	  int wormTailCol = worm -> index(0).getCol();
	  worm -> remove();
	  pool -> insert(grid[wormTailRow][wormTailCol], wormTailRow, wormTailCol);
	  mvaddch(wormTailRow, wormTailCol, ' ');
	}
      refresh();
    }
}

void startup( void )
{
  initscr();	 /* activate the curses */
  clear();	 /* clear the screen that curses provides */
  noecho();	 /* prevent the input chars to be echoed to the screen */
  cbreak();	 /* change the stty so that characters are delivered to the
		    program as they are typed--no need to hit the return key!*/
}

void done(int totalScore)
{
  mvcur( 0, COLS - 1, LINES - 1, 0 );
  clear();
  refresh();
  endwin();
  cout << "Game over! " << endl;
  cout << "Your score was: " << totalScore << endl;
  exit(1);
}


