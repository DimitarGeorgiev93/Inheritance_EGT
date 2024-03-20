#pragma once

#include "ChessPosition.h"

class ChessBoard
{
public:
	ChessBoard();
	
	ChessPosition& GetPosition(const int, const int) const;

	void GetAllMoves(const ChessPosition&) const;

	~ChessBoard();

	void PrintChessBoard() const;

	friend class QueenPiece;
private:

	ChessPosition*** board;
};

