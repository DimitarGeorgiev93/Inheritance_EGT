#pragma once

#include "ChessPosition.h"
#include "ChessBoard.h"

class ChessPiece
{
public:
	ChessPiece(ChessPosition*);
	virtual ~ChessPiece();

	virtual void GetMoves(const ChessBoard&) = 0;
	virtual bool wins(const ChessPosition) const = 0;

	ChessPosition GetPosition() const;

	void PrintAvailablePositions() const;

protected:
	ChessPosition* PiecePosition;
	std::vector<ChessPosition> AvailableMoves;
};

