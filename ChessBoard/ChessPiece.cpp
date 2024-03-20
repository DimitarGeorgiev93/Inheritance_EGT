#include "ChessPiece.h"

ChessPiece::ChessPiece( const char NewPieceType, const bool NewPieceColor, const short NewX = 0, const short NewY = 0):
	PieceColor (NewPieceColor), PieceType(NewPieceType)
{
	if (NewX <= 8 && NewX >= 1 && NewY <= 8 && NewY >= 0) 
	{
		x = NewX;
		y = NewY;
	}
	else 
	{
		x = 0;
		y = 0;
	}
}

ChessPiece::~ChessPiece()
{
}

std::pair<short, short> ChessPiece::GetPosition() const
{
	return std::make_pair(x, y);
}

char ChessPiece::GetPiece() const
{
	return PieceType;
}

bool ChessPiece::GetColor() const
{
	return PieceColor;
}

std::vector<std::pair<short,short>>& ChessPiece::GetAvailableMovesList()
{
	return AvailableMovesList;
}

void ChessPiece::PrintAvailablePositions() const
{
	/*for (const ChessPosition& temp : AvailableMovesList) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;*/
}
