#include "QueenPiece.h"

QueenPiece::QueenPiece(ChessPosition* position): ChessPiece(position)
{
}

QueenPiece::~QueenPiece()
{
}


void QueenPiece::GetMoves( const ChessBoard& chessBoard)
{
	if (GetPosition().x < 1 && GetPosition().x > 8)
	{
		std::cout << "Chess piece is not on the board" << std::endl;
		return;
	}
	int tempX = 0, tempY = 0;
	while (GetPosition().x + tempX++ <= 8)
	{
		if (!chessBoard.board[GetPosition().x + tempX][GetPosition().y]->IsOccupied)
		{
			AvailableMoves.push_back(ChessPosition(GetPosition().x + tempX, GetPosition().y));
		}
	}
	tempX = 0, tempY = 0;
	while (GetPosition().x - tempX++ >= 0)
	{
		if (!chessBoard.board[GetPosition().x - tempX][GetPosition().y]->IsOccupied)
		{
			AvailableMoves.push_back(ChessPosition(GetPosition().x - tempX, GetPosition().y));
		}
	}
	tempX = 0, tempY = 0;

}

bool QueenPiece::wins(const ChessPosition) const
{
	return false;
}
