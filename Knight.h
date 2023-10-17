#pragma once
#include "Piece.h"

class Knight: public Piece
{
public:

	Knight(Color color);
	bool canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces);

};

