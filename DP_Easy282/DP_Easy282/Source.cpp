/*
	Context: https://www.reddit.com/r/dailyprogrammer/comments/5196fi/

	Created by Michael Berger
*/

//Inclusions & Usings
#include "BaseConverter.h";
#include <iostream>;
using std::cout;
using std::endl;

//main()
int main()
{
	//Creating the base converter object
	BaseConverter baseConv = BaseConverter();
	
	//Testing the various input
	cout << "- (b10) 16:\t\t\t" << baseConv.numToFibBin(16) << endl;
	cout << "- (b10) 32:\t\t\t" << baseConv.numToFibBin(32) << endl;
	cout << "- (b10) 9024720:\t\t" << baseConv.numToFibBin(9024720) << endl;
	cout << "- (F) 10:\t\t\t" << baseConv.fibBinToNum("10") << endl;
	cout << "- (F) 1:\t\t\t" << baseConv.fibBinToNum("1") << endl;
	cout << "- (F) 111111:\t\t\t" << baseConv.fibBinToNum("111111") << endl;
	cout << "- (F) 100000:\t\t\t" << baseConv.fibBinToNum("100000") << endl;
	cout << "- (F) 10110110100111001:\t" << baseConv.fibBinToNum("10110110100111001") << endl;
	cout << endl;

	//Returning zero
	return 0;
}