
#include "ChessBoard.h"


ChessBoard::ChessBoard()
{
	board = new ChessPosition * *[8];
	for (int i = 0; i < 8; i++) {
		board[i] = new ChessPosition * [8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = new ChessPosition(i + 1, j + 1);
		}
	}

	//InvalidPosition = ChessPosition();
}

ChessPosition& ChessBoard::GetPosition(const int x, const int y) const
{
	if (!board[x][y])
	{
		std::cout << "Invalid chess board coordinates" << std::endl;
		return InvalidPosition;
	}
	return *board[x][y];
}

ChessBoard::~ChessBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete board[i][j];
			board[i][j] = nullptr;
		}
	}
	for (int i = 0; i < 8; i++) {
		delete[] board[i];
		board[i] = nullptr;
	}
	delete[] board;
}


