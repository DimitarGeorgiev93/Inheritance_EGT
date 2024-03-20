#pragma once

#include <iostream>
#include <vector>
#include "ChessPiece.fwd.h"

struct ChessPosition
{
	ChessPosition(const int x = 0, const int y = 0);
	~ChessPosition();

	friend std::ostream& operator<< (std::ostream&, const ChessPosition&);

	//bool IsOccupied;
	ChessPiece* ChessPieceOnTop = nullptr;
	const int x, y ;
};

static ChessPosition InvalidPosition(0, 0);