#include "ex04-library.h"
#include <iostream>

//Do not modify
Piece::~Piece() {}

//Do not modify
void Piece::printPosition()
{
	cout << "(" << r << "," << c << ")" << endl;
}

WhitePiece::WhitePiece(int r, int c)
{
	this->r = r;
	this->c = c;
}

WhitePiece::~WhitePiece() {}

string WhitePiece::getColor()
{
	return "white";
}

string WhitePiece::printCode()
{
	return "W";
}

void WhitePiece::moveLeft()
{
	this->r -= 1;
	this->c -= 1;
}

void WhitePiece::moveRight()
{
	this->r -= 1;
	this->c += 1;
}

BlackPiece::BlackPiece(int r, int c)
{
	this->r = r;
	this->c = c;
}

BlackPiece::~BlackPiece() {}

string BlackPiece::getColor()
{
	return "black";
}

string BlackPiece::printCode()
{
	return "B";
}

void BlackPiece::moveLeft()
{
	this->r += 1;
	this->c += 1;
}

void BlackPiece::moveRight()
{
	this->r += 1;
	this->c -= 1;
}