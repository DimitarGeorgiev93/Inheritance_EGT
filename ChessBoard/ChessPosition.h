#pragma once

#include <iostream>
#include <vector>
//#include "ChessPiece.fwd.h"
#include "ChessPiece.h"

struct ChessPosition
{
	ChessPosition(const short x = 0, const short y = 0);
	~ChessPosition();

	friend std::ostream& operator<< (std::ostream&, const ChessPosition&);

	//bool IsOccupied;
	ChessPiece* ChessPieceOnTop = nullptr;
	const short x, y ;
};

static ChessPosition InvalidPosition(0, 0);