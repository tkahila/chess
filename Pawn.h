#pragma once

#include "Piece.h"

using namespace std;
class Pawn: public Piece
{
private:
	bool canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces);
public:

	Pawn(Color color, bool _firstStep);
	
	~Pawn();

private:

};

