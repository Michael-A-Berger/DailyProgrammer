/*
	The BaseConverter header. See BaseConverter.cpp for implementation.

	Context: https://www.reddit.com/r/dailyprogrammer/comments/5196fi/

	Created by Michael Berger
*/

#pragma once

//Inclusions & Usings
#include <string>;
#include <iostream>;
using std::cout;
using std::endl;
using std::string;

//The class
class BaseConverter
{
	//Private variables & methods
	private:
		int* fibSeq;
		int size;
		void generateMoreFibNums();

	//Public variables & methods
	public:
		BaseConverter();
		~BaseConverter();
		string numToFibBin(unsigned int numToConv);
		string numToBase10Bin(unsigned int numToConv);
		unsigned int fibBinToNum(string fibToConv);
		unsigned int b10BinToNum(string b10ToConv);

};