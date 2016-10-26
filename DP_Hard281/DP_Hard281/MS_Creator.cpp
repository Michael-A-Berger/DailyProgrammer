/*
Context: https://www.reddit.com/r/dailyprogrammer/comments/50s3ax/

Created by Michael Berger
*/

//Including the header
#include "MS_Creator.h";

//[Constructor]
MS_Creator::MS_Creator()
{
	//Setting the random seed to the current time
	srand(time(0));
}

//[Destructor]
MS_Creator::~MS_Creator()
{
	//IF the map size is greater than zero...
	if (mapWidth > 0   &&   mapHeight > 0)
	{
		//FOR the width of the maps...
		for (int num = 0; num < mapWidth; num++)
		{
			//Deleting the current colums of the maps
			delete[] map[num];
			delete[] publicMap[num];
		}

		//Deleting the rows of the maps
		delete[] map;
		delete[] publicMap;
	}
}

//createRandomMap()
void MS_Creator::createRandomMap(int xSize, int ySize, int numMines)
{
	//Setting the map width and height
	mapWidth = xSize;
	mapHeight = ySize;

	//Creating the map character arrays
	map = new char*[mapWidth];
	publicMap = new char*[mapWidth];
	for (int num = 0; num < mapWidth; num++)
	{
		map[num] = new char[mapHeight];
		publicMap[num] = new char[mapHeight];
	}
	

	//Populating the character arrays with empty spaces
	for (int numY = 0; numY < mapHeight; numY++)
	{
		for (int numX = 0; numX < mapWidth; numX++)
		{
			map[numX][numY] = emptyChar;
			publicMap[numX][numY] = hiddenChar;
		}
	}

	//Placing the mines
	placeMines(numMines);

	//Calculating the remaining spaces
	calcSpaces();
}

//placeMines()
void MS_Creator::placeMines(int numMines)
{
	//FOR every mine that needs to be placed...
	for (int num = 0; num < numMines; num++)
	{
		//Creating the random position variable
		int randPosX = 0;
		int randPosY = 0;

		//DO...
		do
		{
			//Getting a random position on the map
			randPosX = rand() % (mapWidth - 1);
			randPosY = rand() % (mapHeight - 1);
		}
		//...WHILE the random position is a mine (done just to make sure)
		while (map[randPosX][randPosY] == mineChar);

		//Setting the random position to a mine
		map[randPosX][randPosY] = mineChar;
	}
}

//caclSpaces
void MS_Creator::calcSpaces()
{
	//FOR each row in the map...
	for (int numY = 0; numY < mapHeight; numY++)
	{
		//FOR each space in the current row...
		for (int numX = 0; numX < mapWidth; numX++)
		{
			//Creating the amount of nearby mines variable
			int nearbyMines = 0;

			//IF the space isn't a mine... (skips the checks if the space is already a mine)
			if (map[numX][numY] != mineChar)
			{
				//Creating the total nearby mines variable
				int nearbyMines = 0;

				//FOR every nearby space...
				for (int numY2 = -1; numY2 < 2; numY2++)
				{
					for (int numX2 = -1; numX2 < 2; numX2++)
					{
						//IF the nearby space is within the map...
						if (numX + numX2 >= 0   &&   numY + numY2 >= 0
							&&   numX + numX2 < mapWidth   &&   numY + numY2 < mapHeight)
						{
							//IF the space is a mine...
							if (map[numX + numX2][numY + numY2] == mineChar)
							{
								//Increment the nearby mines variable
								nearbyMines++;
							}
						}
					}
				}

				//IF the nearby mines variable is greater than zero...
				if (nearbyMines > 0)
				{
					//Setting the map character to the amount of nearby mines
					map[numX][numY] = 48 + nearbyMines;
				}
			}
		}
	}
}

//printMap()
void MS_Creator::printMap()
{
	//Printing the map header
	for (int num = 0; num < mapWidth * 2 + 15; num++)
	{
		cout << "=";
	}
	cout << endl << endl;

	//FOR every row in the map...
	for (int numY = 0; numY < mapHeight; numY++)
	{
		//Printing out a tab to offset the map
		cout << "\t";

		//FOR every space in the current map row...
		for (int numX = 0; numX < mapWidth; numX++)
		{
			//Printing the current space of the map
			cout << map[numX][numY] << ' ';
		}

		//Setting the console output to the next line
		cout << endl;
	}
	cout << endl;

	//Printing the map tail
	for (int num = 0; num < mapWidth * 2 + 15; num++)
	{
		cout << "=";
	}
	cout << endl;
}

//retrievePublicMap()
char** MS_Creator::retrievePublicMap()
{
	//Printing the public map header
	for (int num = 0; num < mapWidth * 2 + 15; num++)
	{
		cout << "=";
	}
	cout << endl << endl;

	//FOR every row in the map...
	for (int numY = 0; numY < mapHeight; numY++)
	{
		//Printing out a tab to offset the map
		cout << "\t";

		//FOR every space in the current map row...
		for (int numX = 0; numX < mapWidth; numX++)
		{
			//Printing the current space of the map
			cout << publicMap[numX][numY] << ' ';
		}

		//Setting the console output to the next line
		cout << endl;
	}
	cout << endl;

	//Printing the public map tail
	for (int num = 0; num < mapWidth * 2 + 15; num++)
	{
		cout << "=";
	}
	cout << endl;

	//Returning the public map
	return publicMap;
}

//revealSpace()
void MS_Creator::revealSpace(int xPos, int yPos)
{
	//Making sure the positions stay on the board
	xPos = abs(xPos) % mapWidth;
	yPos = abs(yPos) % mapHeight;

	//Revealing the space on the map
	publicMap[xPos][yPos] = map[xPos][yPos];

	//IF the space was empty...
	if (publicMap[xPos][yPos] == emptyChar)
	{
		//FOR every adjacent space...
		for (int numY = -1; numY < 2; numY++)
		{
			for (int numX = -1; numX < 2; numX++)
			{
				//IF the adjacent space exists on the board...
				if (xPos + numX == abs(xPos + numX) % mapWidth
					&&   yPos + numY == abs(yPos + numY) % mapHeight
					&&   publicMap[xPos + numX][yPos + numY] == hiddenChar)
				{
					//Reveal the adjacent space
					revealSpace(xPos + numX, yPos + numY);
				}
			}
		}
	}

	//
}

//isGameOver()
bool MS_Creator::isGameOver()
{
	//Returning whether the game is over
	return gameOver;
}