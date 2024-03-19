#include "ChessPosition.h"

ChessPosition::ChessPosition(const int x , const int y ): x(x), y(y)
{
	//Piece = nullptr;
	IsOccupied = false;
}

ChessPosition::~ChessPosition()
{
}


std::ostream& operator<<(std::ostream& output, const ChessPosition& piece)
{
	if (piece.x == 0 && piece.y == 0)
	{
		output << piece.x  << piece.y;
	}
	else 
	{
		output << char(piece.x + 64) << piece.y;
	}
	return output;
}
