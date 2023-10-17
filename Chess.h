#pragma once

#include <vector>
#include <iostream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <string>
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include <memory>
#include <iterator>
#include <map>

using namespace std;

class Chess
{

private:

	
public:

	Chess();
	void start();
	bool fillBoard(string filename);
	void printBoard();
	bool checkTurn(int oldX, int oldY);
	void save();
	bool readInput(string sentence);
	bool movePiece(int oldX, int oldY, int newX, int newY);
	bool initializeDone = false;
	bool blackTurn = false;
	vector<vector<shared_ptr<Piece>>> pieces;
	Color turn;


	~Chess();
};

