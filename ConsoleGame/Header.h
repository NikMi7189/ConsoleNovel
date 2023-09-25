#include <iostream>
#include <string>
#include <fstream>
#include "conio.h"
#include "windows.h"
#include <algorithm>
#include <direct.h>

using namespace std;

const int stringTypeCount = 3;
const int menuItemsCount = 3;
const int minCount = 1;
const string splitSymbol = "|";
const int timeLoading = 30;
const int readerSize = 4096;
const int gameMode = 1;
const int menuMode = 2;

enum MainMenuItems
{
	startGame = 1,
	loadGame = 2,
	exitGame = 3
};

enum StringType
{
	text = 1,
	question = 2,
	ways = 3
};
