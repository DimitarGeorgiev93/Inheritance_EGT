
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

void ChessBoard::GetAllMoves(const ChessPosition& chessPosition) const
{
	if (chessPosition.ChessPieceOnTop == nullptr)
	{
		std::cout << "No piece on that position" << std::endl;
		return;
	}
	switch (chessPosition.ChessPieceOnTop->GetPiece()) {
	case 'q':
		break;
	case 'n':
		break;
	case 'r':
		break;
	default:
		break;
	}

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

void ChessBoard::PrintChessBoard() const
{
		std::cout << "black pieces, lowercase" << std::endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j]->ChessPieceOnTop != nullptr) {
				std::cout << board[i][j]->ChessPieceOnTop->GetPiece() << " ";
			}
			else std::cout << '_' << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "white pieces, uppercase" << std::endl;
}


