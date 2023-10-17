
#include "Knight.h"
#include <math.h>  


Knight::Knight(Color _color)
{
	color = _color;
	id = PIECE;
	name = "NKnight";
	symbol = "N";
}

bool Knight::canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces) {

	int deltaX = newX - oldX;
	int deltaY = newY - oldY;

	//jos pituus eri kuin neli�juuri 5 
	if (sqrt(deltaX*deltaX + deltaY*deltaY) != sqrt(5)) {
		return false;
	}
	
	if (this->color == pieces[newX][newY]->color) {
		return false;
	}
	

	return true;
}

