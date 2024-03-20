
#include <iostream>
#include "ChessBoard.h"
#include "ChessPiece.h"

int main()
{
	ChessBoard A;

	ChessPiece B('c',true, 2,3);

	ChessPosition temp = A.GetPosition(3, 2);
	std::cout << temp;

	A.PrintChessBoard();
	//temp.ChessPieceOnTop = &B;
	//std::cout << temp.ChessPieceOnTop->GetPosition();
	return 0;
}