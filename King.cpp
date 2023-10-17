
#include "King.h"


King::King(Color _color)
{
	color = _color;
	id = PIECE;
	name = "King";
	symbol = "K";

}

bool King::canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces) {

	//cout << "King move" << endl;

	//jos askel  enemm�nkuin 1 
	if ((abs(oldY - newY) > 1) || (abs(oldX - newX)) > 1) {
		return false;
	}

	//jos sama v�ri 
	if (this->color == pieces[newX][newY]->color) {
		return false;
	}

	return true;
}


