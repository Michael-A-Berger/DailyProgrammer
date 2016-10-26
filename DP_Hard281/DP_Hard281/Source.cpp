/*
	Context: https://www.reddit.com/r/dailyprogrammer/comments/50s3ax/

	Created by Michael Berger
*/

//Inclusions & Usings
#include <iostream>;
#include "MS_Creator.h";
using std::cout;
using std::endl;
using std::cin;

//main()
int main()
{
	//Creating the Minesweeper creator
	MS_Creator msc;

	//TEST TEST TEST
	msc.createRandomMap(10, 10, 10);
	msc.printMap();
	msc.retrievePublicMap();
	msc.revealSpace(rand() % 10, rand() % 10);
	msc.retrievePublicMap();
	msc.revealSpace(rand() % 10, rand() % 10);
	msc.retrievePublicMap();
	msc.revealSpace(rand() % 10, rand() % 10);
	msc.retrievePublicMap();
	cin.get();
	//TEST TEST TEST

	//Returning zero
	return 0;
}