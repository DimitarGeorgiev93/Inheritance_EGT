#pragma once
#include "ChessPiece.h"
class RookPiece :
    public ChessPiece
{
public:
    RookPiece(const char, const bool, const bool, const short, const short);
    ~RookPiece();
    bool GetRookColor() const;
private:
    const bool RookColor;
};

