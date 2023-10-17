
#include "Piece.h"

Piece::Piece() {
}

Piece::Piece(ID id)
{
	this->name = "Tile";
	this->id = id;
	this->color = Color::BROWN;
	symbol = 176;
	firstStep = true;
}


bool Piece::canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces) {
	//cout << "square move" << endl;
	return false;
}

ostream &operator<<(ostream & out, const Piece &Piece) {

	out << Piece.symbol;
	return out;
}


bool Piece::iterate(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces) {

	int sx = oldX < newX ? 1 : -1;
	int sy = oldY < newY ? 1 : -1;

	while (1) {

		if (oldX != newX) {
			oldX += sx;
		}
		if (oldY != newY) {
			oldY += sy;
		}

		if ((oldX == newX) && (oldY == newY)) break;

		//jos linjalla joku
		if (pieces[oldX][oldY]->id == PIECE) {
			return false;
		}
	}
	return true;
}


Piece::~Piece()
{
}
