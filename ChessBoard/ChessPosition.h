#pragma once

#include <iostream>
#include <vector>


struct ChessPosition
{
//public:
	ChessPosition(const int x = 0, const int y = 0);
	~ChessPosition();

	/*bool GetIsOccupied() const;
	void Occupy();*/

	friend std::ostream& operator<< (std::ostream&, const ChessPosition&);

	bool IsOccupied;
	const int x, y ;
};

static ChessPosition InvalidPosition(0, 0);