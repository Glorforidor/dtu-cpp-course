#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell **createAndInitBoard(int n)
{
	// initialise board
	cell **board = new cell *[n];
	for (int i = 0; i < n; i++)
	{
		board[i] = new cell[n];
	}

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cellColor color = computeColor(r, c);
			board[r][c].color = color;

			// If the color is not dark do not change status.
			if (color != dark)
			{
				continue;
			}
			// The first three rows.
			if (r == 0 || r == 1 || r == 2)
			{
				board[r][c].status = blackPiece;
			}
			// The last three rows.
			else if (r == n - 1 || r == n - 2 || r == n - 3)
			{
				board[r][c].status = whitePiece;
			}
		}
	}

	return board;
}

//Exercise 1 (b) Implement this function
cell **duplicateBoard(cell **A, int n)
{
	cell **boardCopy = new cell *[n];
	for (int i = 0; i < n; i++)
	{
		boardCopy[i] = new cell[n];
	}
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			boardCopy[r][c] = A[r][c];
		}
	}

	return boardCopy;
}

//Exercise 1 (c) Implement this function
bool moveRight(cell **A, int n, int r, int c)
{
	// The piece is outside the board!
	if (r < 0 || r > n - 1 || c < 0 || c > n - 1)
	{
		return false;
	}

	// Get the source cell and check it is not empty.
	cell *source = &A[r][c];
	if (source->status == emptyC)
	{
		return false;
	}

	int newRow = 0;
	int newCol = 0;
	cell *target;
	switch (source->status)
	{
	case blackPiece:
		newRow = r + 1;
		newCol = c - 1;
		// Check we do not move the pierce overboard.
		if (newRow < 0 || newRow > n - 1 || newCol < 0 || newCol > n - 1)
		{
			return false;
		}
		target = &A[newRow][newCol];
		if (target->status != emptyC)
		{
			return false;
		}

		// Move the pierce.
		target->status = source->status;
		source->status = emptyC;

		break;
	case whitePiece:
		// Check we do not move the pierce overboard.
		newRow = r - 1;
		newCol = c + 1;
		if (newRow < 0 || newRow > n - 1 || newCol < 0 || newCol > n - 1)
		{
			return false;
		}
		target = &A[newRow][newCol];
		if (target->status != emptyC)
		{
			return false;
		}

		// Move the pierce.
		target->status = source->status;
		source->status = emptyC;
		break;
	default:
		// If we reach here, the code provided failed!
		return false;
	}

	// So true if we reach here!
	return true;
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell **A, int n, int r, int c)
{
	// The piece is outside the board!
	if (r < 0 || r > n - 1 || c < 0 || c > n - 1)
	{
		return false;
	}

	// Get the source cell and check it is not empty.
	cell *source = &A[r][c];
	if (source->status == emptyC)
	{
		return false;
	}

	int newRow = 0;
	int newCol = 0;
	cell *target;
	switch (source->status)
	{
	case blackPiece:
		newRow = r + 1;
		newCol = c + 1;
		// Check we do not move the pierce overboard.
		if (newRow < 0 || newRow > n - 1 || newCol < 0 || newCol > n - 1)
		{
			return false;
		}
		target = &A[newRow][newCol];
		if (target->status != emptyC)
		{
			return false;
		}

		// Move the pierce.
		target->status = source->status;
		source->status = emptyC;
		break;
	case whitePiece:
		// Check we do not move the pierce overboard.
		newRow = r - 1;
		newCol = c - 1;
		if (newRow < 0 || newRow > n - 1 || newCol < 0 || newCol > n - 1)
		{
			return false;
		}
		target = &A[newRow][newCol];
		if (target->status != emptyC)
		{
			return false;
		}

		// Move the pierce.
		target->status = source->status;
		source->status = emptyC;
		break;

	default:
		// If we reach here, the code provided failed!
		return false;
	}

	// So true if we reach here!
	return true;
}

//Do not modify
cellColor computeColor(int r, int c)
{
	if ((r % 2 == 0 && c % 2 == 0) || (r % 2 != 0 && c % 2 != 0))
	{
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell **A, int n)
{
	cout << ' ';
	for (int c = 0; c < n; c++)
	{
		cout << c;
	}
	cout << endl;
	for (int r = 0; r < n; r++)
	{
		cout << r;
		for (int c = 0; c < n; c++)
		{
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status)
			{
			case emptyC:
				cout << ((A[r][c].color == bright) ? ' ' : '#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
