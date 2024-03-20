#pragma once

//#include "ChessPosition.h"
//#include "ChessBoard.h"
#include<iostream>
#include<vector>

class ChessPiece
{
public:
	ChessPiece(const char, const bool, const short, const short);
	virtual ~ChessPiece();

	std::pair<short, short> GetPosition() const;
	char GetPiece() const;
	bool GetColor() const;

	std::vector<std::pair<short, short>>& GetAvailableMovesList();
	void PrintAvailablePositions() const;

protected:
	short x, y;
	std::vector<std::pair<short,short>> AvailableMovesList;
	const char PieceType;
	const bool PieceColor; // true = white, uppercase // false = black, lowercase
};

