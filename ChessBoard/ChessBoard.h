#pragma once

#include "ChessPosition.h"

class ChessBoard
{
public:
	ChessBoard();
	
	ChessPosition& GetPosition(const int, const int) const;

	~ChessBoard();

	friend class QueenPiece;
private:

	ChessPosition*** board;
};

