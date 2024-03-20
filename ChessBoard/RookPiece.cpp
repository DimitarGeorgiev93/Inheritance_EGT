#include "RookPiece.h"

RookPiece::RookPiece(const char NewPieceType, const bool NewPieceColor, const bool NewRookColor, const short NewX = 0, const short NewY = 0) 
	: ChessPiece(NewPieceType, NewPieceColor, NewX, NewY), RookColor (NewRookColor)
{
}

RookPiece::~RookPiece()
{
}

bool RookPiece::GetRookColor() const
{
	return RookColor;
}
