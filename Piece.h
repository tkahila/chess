#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdio.h>  
#include <string>
#include <stdio.h> 
#include <memory>
//#include "Chess.h"

using namespace std;

enum class Color
{
	BLACK = 8,
	WHITE = 15,
	BROWN = 6
};

class Piece
{
	
	friend ostream& operator<<(ostream &out, const Piece &piece);

public:


	enum ID
	{
		PIECE,
		TILE
	};

	Color color;
	ID id;
	Piece();

	virtual bool canImove(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces);
	static Piece *makePiece(string choice,Color colo, bool firstStep);
	bool iterate(int oldX, int oldY, int newX, int newY, vector<vector<shared_ptr<Piece>>> &pieces);

	Piece(ID id);
	string name = "";
	string symbol = "";
	bool firstStep;
	~Piece();


};

