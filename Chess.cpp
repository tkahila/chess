
#include "Chess.h"

using namespace std;


//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Piece *Piece::makePiece(string choice, Color color, bool firstStep)
{
	if (choice == "King")
		return new King(color);
	else if (choice == "Queen")
		return new Queen(color);
	else if (choice == "Pawn")
		return new Pawn(color,firstStep);
	else if (choice == "NKnight")
		return new Knight(color);
	else if (choice == "Rook")
		return new Rook(color);
	else if (choice == "Bishop")
		return new Bishop(color);
	else
		return new Piece(Piece::TILE);
}


Chess::Chess():pieces(8, vector<shared_ptr<Piece>>(8))
{
}

bool Chess::checkTurn(int oldX, int oldY) {
	if ((pieces[oldX][oldY]->color == Color::BLACK) && (blackTurn == true)) {
		return true;
	}
	if ((pieces[oldX][oldY]->color == Color::WHITE) && (blackTurn == false)) {
		return true;
	}
	cout << "Trying to move wrong color" << endl;
	return false;
}

bool Chess::movePiece(int oldX,int oldY,int newX, int newY) {


	if ((pieces[oldX][oldY]->canImove(oldX,oldY,newX, newY, this->pieces)) && checkTurn(oldX,oldY)) {

		pieces[newX][newY] = pieces[oldX][oldY];
		pieces[oldX][oldY] = shared_ptr<Piece>(new Piece(Piece::TILE));
		return true;
	}
	else {
		cout << "invalid move, try again" << endl;
		return false;
	}

}

bool Chess::fillBoard(string filename) {

	string piece, color, line, temp, allPieces;
	bool firstStep;
	string delimeter = ":";

	ifstream myfile(filename);

	map<string, Color> colors;
	colors.insert(make_pair("BLACK", Color::BLACK));
	colors.insert(make_pair("WHITE", Color::WHITE));
	colors.insert(make_pair("BROWN", Color::BROWN));

	while (getline(myfile, line)) {
		allPieces.append(line);
		line.erase();
	}

	string parameterstart = "<chess>";
	string parameterend = "</chess>";
	size_t startposition = allPieces.find(parameterstart);
	size_t endposition = allPieces.find(parameterend);

	if ((startposition == string::npos) || (endposition == string::npos)) {
		cout << "ERROR. Corrupted file" << endl;
		return false;
	}
	else
	{
		startposition += parameterstart.size();
		allPieces = allPieces.substr(startposition, endposition - startposition);
	}


		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				temp = allPieces.substr(0, allPieces.find(","));
				allPieces.erase(0, temp.length()+1);

				piece = temp.substr(0, temp.find(delimeter));
				temp.erase(0, piece.length() + 1);

				color = temp.substr(0, temp.find(delimeter));
				temp.erase(0, color.length() + 1);

				firstStep = stoi(temp);
				//cout << firstStep;

				auto it = colors.find(color);

				pieces[j][i] = shared_ptr<Piece>(Piece::makePiece(piece, it->second, firstStep));
					
			}
	}

	//get turn
	blackTurn = stoi(allPieces.substr(allPieces.find(delimeter) + 1));
	//cout << "turn is: "<< blackTurn;
	myfile.close();
	initializeDone = true;
	printBoard();
	return true;
}



void Chess::printBoard() {

	//print abcde....
	//SetConsoleTextAttribute(hConsole, 14);
	cout << endl << "   ";
	for (int i = 65; i < 73; i++) {
		cout << char(i) << "  ";
	}

	cout << endl << endl<< endl;
	
	for (size_t i = 0; i < pieces.size(); i++) {

		//SetConsoleTextAttribute(hConsole, 14);
		cout << i + 1 << "  ";

		for (size_t j = 0; j < pieces.size(); j++){

			//SetConsoleTextAttribute(hConsole, int(pieces[j][i]->color));
			//cout << int(pieces[j][i]->color);
			cout << *pieces[j][i] << "  ";
		}

		//SetConsoleTextAttribute(hConsole, 14);
		cout << " " << i+1;
		cout << endl << endl;
	}

	//SetConsoleTextAttribute(hConsole, 14);
	cout << endl << "   ";
	for (int i = 65; i < 73; i++) {
		cout << char(i) << "  ";
	}
	//SetConsoleTextAttribute(hConsole, 7);

	cout <<endl<< endl<< (blackTurn ? "Black turn" : "White turn") << endl;
}

void Chess::save() {
	
	if (initializeDone) {
		map<Color, string> colors;
		colors.insert(make_pair(Color::BLACK, "BLACK"));
		colors.insert(make_pair(Color::WHITE, "WHITE"));
		colors.insert(make_pair(Color::BROWN, "BROWN"));

		string filename = "save.txt";
		//string filename = "startsequence.txt";
		ofstream out(filename);

		if (out.is_open()) {

			out << "<chess>" << endl;

			for (size_t i = 0; i < pieces.size(); i++) {
				for (size_t j = 0; j < pieces.size(); j++) {

					//out << "{"<< pieces[j][i]->name<<":"<< pieces[j][i]->color << "}";
					out << pieces[j][i]->name << ":";
					auto it = colors.find(pieces[j][i]->color);
					out << it->second << ":";
					//cout << "rist: " << pieces[j][i]->firstStep <<endl;
					out << pieces[j][i]->firstStep;
					out << "," << endl;
				}
			}
			out << "turn:" << blackTurn << endl;
			out << "</chess>" << endl;
		}
		out.close();

		cout << "Game saved succesfully!" << endl;

	}
	else {
		cout << "Cannot save game." << endl;
	}
	
}

void printHelp() {
	cout << "Command list:\n\n"
		"new game\n"
		"load game\n"
		"save game\n"
		"help\n"
		"exit\n\n"
		"Move example:\n"
		"move a2 to a3, type: a2a3\n\n";
}

bool Chess::readInput(string sentence) {

	cout << sentence;
	string input = "";
	getline(cin, input);

	if (input == "exit") {
		return false;
	}
	else if (input == "new game") {
		fillBoard("startsequence.txt");	
	}
	else if (input == "save game") {
		save();
	}
	else if (input == "load game") {
		fillBoard("save.txt");
	}
	else if (input.substr(0, 1) >= "a" && input.substr(0, 1) <= "h" &&
		input.substr(1, 1) >= "1" && input.substr(1, 1) <= "8" &&
		input.substr(2, 1) >= "a" && input.substr(2, 1) <= "h" &&
		input.substr(3, 1) >= "1" && input.substr(3, 1) <= "8" && initializeDone) {

		int oldX = input[0] - 'a';
		int oldY = input[1] - '1';
		int newX = input[2] - 'a';
		int newY = input[3] - '1';

		if (movePiece(oldX, oldY, newX, newY)) {
			blackTurn = !blackTurn;
			printBoard();
		}

	}
	else if (input == "help") {
		printHelp();
	}
	else {
		cout << "Unknown command. Type help for help" << endl;
	}

	return true;

}

void Chess::start() {

	printHelp();
		while (true) {

			if (!readInput(">")) break;

		}

}
Chess::~Chess()
{
}
