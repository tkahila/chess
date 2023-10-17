
#include "Bishop.h"


Bishop::Bishop(Color _color)
{
	color = _color;
	id = PIECE;
	name = "Bishop";
	symbol = "B";

}

bool Bishop::canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces) {


	//jos ei yl�viistoon 
	if ((abs(newX - oldX)) != (abs(newY - oldY))) {
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


