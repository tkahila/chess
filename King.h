#pragma once
#include "Piece.h"
using namespace std;

class King : public Piece
{
private:
	bool canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces);
public:

	King(Color color);


};

