/*
	Context: https://www.reddit.com/r/dailyprogrammer/comments/55zdxx/

	Created by Michael Berger
*/
#pragma once

//Inclusions & Usings
#include <iostream>;
#include <string>;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

//The Calculator class
class Calculator
{
	//Public methods & variables
	public:
		Calculator();
		~Calculator();
		void printFibSeq();
		string giveZeckendorfRep(int number);

	//Private methods & variables
	private:
		void moreFibNumbers();
		int* fibSeq;
		int sizeSeq;
};