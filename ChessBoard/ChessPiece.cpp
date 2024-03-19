#include "ChessPiece.h"

ChessPiece::ChessPiece( ChessPosition* position)
{
	if (position != nullptr) 
	{
		PiecePosition = position;
	}
	else 
	{
		PiecePosition = &InvalidPosition;
	}
}

ChessPiece::~ChessPiece()
{
}

ChessPosition ChessPiece::GetPosition() const
{
	return *PiecePosition;
}

void ChessPiece::PrintAvailablePositions() const
{
	for (const ChessPosition& temp : AvailableMoves) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}
