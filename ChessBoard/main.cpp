
#include <iostream>
#include "ChessBoard.h"


int main()
{
	ChessBoard A;
	ChessPosition temp = A.getPosition(3, 2);
	std::cout << temp;
}