// projekti.cpp : Defines the entry point for the console application.

#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdio.h>  
#include <string>
#include "Chess.h"

#ifdef _DEBUG // Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated
#include <crtdbg.h> // runtime debug functions are declared here
#endif

using namespace std;


int main()
{
	{
		Chess chess;
		chess.start();
	}
	
	//_CrtDumpMemoryLeaks();
	//system("PAUSE");

	return 0;
}


