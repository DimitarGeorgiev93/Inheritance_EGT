
#include <iostream>
#include "ChessBoard.h"
#include "ChessPiece.h"

int main()
{
	ChessBoard A;

	ChessPiece B('c',true, &InvalidPosition);

	ChessPosition temp = A.getPosition(3, 2);
	std::cout << temp;
	temp.ChessPieceOnTop = &B;
	std::cout << temp.ChessPieceOnTop->GetPosition();

}