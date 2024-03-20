#include "ChessPiece.h"

ChessPiece::ChessPiece( const char NewPieceType, const bool NewPieceColor, ChessPosition* position = nullptr):
	PieceColor (NewPieceColor), PieceType(NewPieceType)
{
	if (position != nullptr) 
	{
		PiecePosition = position;
	}
	else 
	{
		PiecePosition = &InvalidPosition; // to fix later
	}
}

ChessPiece::~ChessPiece()
{
}

ChessPosition ChessPiece::GetPosition() const
{
	return *PiecePosition;
}

char ChessPiece::GetPiece() const
{
	return PieceType;
}

bool ChessPiece::GetColor() const
{
	return PieceColor;
}

std::vector<ChessPosition>& ChessPiece::GetAvailableMovesList()
{
	return AvailableMovesList;
}

void ChessPiece::PrintAvailablePositions() const
{
	for (const ChessPosition& temp : AvailableMovesList) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}
