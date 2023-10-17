
#include "Pawn.h"
#include <math.h>  

Pawn::Pawn(Color _color, bool _firstStep)
{
	color = _color;
	id = PIECE;
	name = "Pawn";
	symbol = "P";
	firstStep = _firstStep;
}


bool Pawn::canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces) {

	//k��nn� logiikka

	//jos sivulle enemm�nku 1 tai samalle sivulle
	if ((abs(oldX - newX) > 1) || (oldY == newY)) {
		//cout << "taalta" << endl;
		return false;
	}
	
	//jos askel eteen yli 1 eik� ekasteppi
	if ((abs(oldY - newY) > 1) && !firstStep) {
		//cout << "taalta1" << endl;
		return false;
	}

	if ((abs(oldY - newY) > 2)) {
		//cout << "taalta2" << endl;
		return false;
	}

	//jos yksi eteen ja joku edess�
	if ((oldX == newX) && (pieces[newX][newY]->id == PIECE)) {
		//cout << "eri v�ri"<<endl;
		return false;
	}
	
	//jos viistoon eik� sy�t�v�� 
	int deltaX = newX - oldX;
	int deltaY = newY - oldY;

	if ((sqrt(deltaX*deltaX + deltaY*deltaY) == sqrt(2)) && (pieces[newX][newY]->id == TILE)) {
		//cout << "taalta3" << endl;
		return false;
	}
	if (sqrt(deltaX*deltaX + deltaY*deltaY) > sqrt(4)) {
		//cout << "taaltaaaaa" << endl;
		return false;
	}

	//jos musta menee taakse 
	if (this->color == Color::BLACK) {
		if ((oldY - newY) > 1) {
			//cout << "taalta4" << endl;
			return false;
		}
	} 

	//jos valkoinen menee taakse
	if (this->color == Color::WHITE) {
		if ((oldY - newY) < 0) {
			//cout << "taalta5" << endl;
			return false;
		}
	}

	//jos sama v�ri
	if (this->color == pieces[newX][newY]->color) {
		//cout << "taalta6" << endl;
		return false;
	}

	//iteroi
	if (!iterate(oldX, oldY, newX, newY, pieces)) {
		return false;
	}
	
	firstStep = false;
	return true;
}

