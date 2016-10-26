/*
	Context: https://www.reddit.com/r/dailyprogrammer/comments/50s3ax/

	Created by Michael Berger
*/
#pragma once

//Inclusions & Usings
#include <iostream>;
#include <ctime>;
using std::cout;
using std::endl;
using std::cin;

//The MS_Creator class
class MS_Creator
{
	//Public variables & methods
	public:
		MS_Creator();
		~MS_Creator();
		void createRandomMap(int xSize, int ySize, int numMines);
		void printMap();
		char** retrievePublicMap();
		void revealSpace(int x, int y);
		bool isGameOver();

	//Private variables & methods
	private:
		void placeMines(int numMines);
		void calcSpaces();
		char** map;
		char** publicMap;
		bool gameOver = false;
		int mapWidth = 0;
		int mapHeight = 0;
		char mineChar = 'X';
		char emptyChar = '-';
		char hiddenChar = '?';
};