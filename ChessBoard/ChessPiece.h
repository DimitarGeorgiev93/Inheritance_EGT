#pragma once

#include "ChessPosition.h"
#include "ChessBoard.h"

class ChessPiece
{
public:
	ChessPiece(const char, const bool, ChessPosition*);
	virtual ~ChessPiece();

	virtual void GetMoves(const ChessBoard&) {};
	virtual bool wins(const ChessPosition) const {
		return true;
	};

	ChessPosition GetPosition() const;
	char GetPiece() const;
	bool GetColor() const;

	std::vector<ChessPosition>& GetAvailableMovesList();
	void PrintAvailablePositions() const;

protected:
	ChessPosition* PiecePosition;
	std::vector<ChessPosition> AvailableMovesList;
	const char PieceType;
	const bool PieceColor; // true = white, uppercase // false = black, lowercase
};

