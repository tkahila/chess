
#include "Queen.h"



Queen::Queen(Color _color)
{
	color = _color;
	id = PIECE;
	name = "Queen";
	symbol = "Q";
}

bool Queen::canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces) {


	//jos ei viistoon tai sivuille
	if (((abs(newX - oldX)) != (abs(newY - oldY))) && ((oldX != newX) && (oldY != newY))) {
		return false;
	}

	//jos sama v�ri
	if (this->color == pieces[newX][newY]->color) {
		return false;
	}

	//ITEROI
	if (!iterate(oldX, oldY, newX, newY, pieces)) {
		return false;
	}

	return true;
}


