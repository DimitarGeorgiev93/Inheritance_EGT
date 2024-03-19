#pragma once
#include "ChessPiece.h"

class QueenPiece :
    public ChessPiece
{
public:
    QueenPiece( ChessPosition* );
    ~QueenPiece();

    void GetMoves(const ChessBoard&) override;
    bool wins(const ChessPosition) const override;
};

