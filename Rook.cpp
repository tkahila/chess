
#include "Rook.h"


Rook::Rook(Color _color)
{
	color = _color;
	id = PIECE;
	name = "Rook";
	symbol = "R";
}


bool Rook::canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces) {


	//jos kumpikaan ei ole samalla linjalla
	if ((oldX != newX) && (oldY != newY)) {
		return false;
	}

	//jos sama v�ri 
	if (this->color == pieces[newX][newY]->color) {
		return false;
	}


	//iteroi l�pi jos edess� joku
	if (!iterate(oldX, oldY, newX, newY, pieces)) {
		return false;
	}

	return true;
}


