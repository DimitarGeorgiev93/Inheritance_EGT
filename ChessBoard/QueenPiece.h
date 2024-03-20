#pragma once
#include "ChessPiece.h"

class QueenPiece :
    public ChessPiece
{
public:
    QueenPiece(const char, const bool, const short, const short);
    ~QueenPiece();

    /*void GetMoves(const ChessBoard&) override;
    bool wins(const ChessPosition) const override;*/
};

