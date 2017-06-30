#include "stdafx.h"
#include "History.h"
#include "globals.h"


#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
	nRows = MAXROWS;
	nCols = MAXCOLS;
}

bool History::record(int r, int c)
{
	if (r <= 0 || c <= 0 || r > m_rows || c > m_cols)	
		return false;

	m_arenaHistory[r - 1][c - 1]++;	
	return true;
}
void History::display() const
{
	clearScreen();

	int r, c;
	char displayHistory[MAXROWS][MAXCOLS];
	for (r = 1; r <= m_rows; r++)
		for (c = 1; c <= m_cols; c++)
		{
			int count = m_arenaHistory[r - 1][c - 1];	
			if (count == 0)
				displayHistory[r - 1][c - 1] = '.';	
			else if (count >= 26)
				displayHistory[r - 1][c - 1] = 'Z';	
			else
				displayHistory[r - 1][c - 1] = 64 + count;	
		}
	for (r = 1; r <= m_rows; r++)
	{
		for (c = 1; c <= m_cols; c++)
			cout << displayHistory[r - 1][c - 1];	//Display history grid
		cout << endl;
	}
	cout << endl;
}