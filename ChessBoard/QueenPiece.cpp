#include "QueenPiece.h"

QueenPiece::QueenPiece(const char NewPieceType, const bool NewPieceColor, const short NewX = 0 , const short NewY = 0)
	: ChessPiece(NewPieceType, NewPieceColor, NewX, NewY)
{
}

QueenPiece::~QueenPiece()
{
}


//void QueenPiece::GetMoves( const ChessBoard& chessBoard)
//{
//	if (GetPosition().first < 1 && GetPosition().first > 8)
//	{
//		std::cout << "Chess piece is not on the board" << std::endl;
//		return;
//	}
//	int tempX = 0, tempY = 0;
//	while (GetPosition().first + tempX++ <= 8)
//	{
//		if (!chessBoard.board[GetPosition().first + tempX][GetPosition().second]->ChessPieceOnTop)
//		{
//			AvailableMovesList.push_back(ChessPosition(GetPosition().first + tempX, GetPosition().second));
//		}
//	}
//	tempX = 0, tempY = 0;
//	while (GetPosition().first - tempX++ >= 0)
//	{
//		if (!chessBoard.board[GetPosition().first - tempX][GetPosition().second]->ChessPieceOnTop)
//		{
//			AvailableMovesList.push_back(ChessPosition(GetPosition().first - tempX, GetPosition().second));
//		}
//	}
//	tempX = 0, tempY = 0;
//
//}
//
//bool QueenPiece::wins(const ChessPosition) const
//{
//	return false;
//}
