/*
	The BaseConverter.cpp class. Is used to convert base-10 numbers to
	base-fibonacci numbers.

	Context: https://www.reddit.com/r/dailyprogrammer/comments/5196fi/

	Created by Michael Berger
*/

//Including the header
#include "BaseConverter.h";

//[Constructor]
BaseConverter::BaseConverter()
{
	//Creating the Fibonacci array pointer
	fibSeq = new int[4];

	//Putting the first 5 Fibonacci numbers in the Fibonacci array
	*fibSeq = 1;
	*(fibSeq + 1) = 1;
	*(fibSeq + 2) = 2;
	*(fibSeq + 3) = 3;

	//Setting the size and capacity variables
	size = 4;
}

//[Destructor]
BaseConverter::~BaseConverter()
{
	//Deleting the Fibonacci array
	delete[] fibSeq;
}

//numToFibBin()
string BaseConverter::numToFibBin(unsigned int numToConv)
{
	//Defining the result
	string result;

	//Defining the Fibonacci size comparison variables
	int modNum = numToConv % *(fibSeq + size - 1);
	int subNum = numToConv - *(fibSeq + size - 1);
	
	//WHILE the largest generated Fibonacci number is too small...
	while (modNum < subNum)
	{
		//Generating more Fibonacci numbers
		generateMoreFibNums();

		//Calculating the Fibonacci size comparison variables
		modNum = numToConv % *(fibSeq + size - 1);
		subNum = numToConv - *(fibSeq + size - 1);
	}

	//FOR each generated Fibonacci number...
	for (int num = size - 1; num >= 0; num--)
	{
		//IF the number to convert modded by the Fibonacci number at the iterator is less than itself...
		if (numToConv % *(fibSeq + num) < numToConv)
		{
			//Subtracting the number to convert by the Fibonacci number
			numToConv -= *(fibSeq + num);

			//Adding '1' to the result string
			result += '1';
		}
		//ELSE IF the result string isn't empty...
		else if (result != ""   ||   num == 0)
		{
			//Adding '0' to the result string
			result += '0';
		}
	}

	//Returning the result
	return result;
}

//numToBase10()
string BaseConverter::numToBase10Bin(unsigned int numToConv)
{
	//Defining the result
	string result;

	//FOR 31 iterations...
	for (int num = 31; num > 0; num--)
	{
		//IF the number to convert modded by 2 ^ the iterator isn't itself...
		if (numToConv % (int) pow(2, num) != numToConv)
		{
			//Subtracting from the number to convert
			numToConv -= (int) pow(2, num);

			//Adding '1' to the result string
			result += '1';
		}
		//ELSE IF the result string isn't empty
		else if (result != "")
		{
			//Adding '0' to the result string
			result += '0';
		}
	}

	//Adding the remaining number (1 or 0) to the result string
	switch (numToConv)
	{
		case 0:
			result += '0';
			break;
		case 1:
			result += '1';
			break;
		default:
			cout << "- numToConv =/= '1' || '0'!" << endl;
			break;
	}

	//Returning the result
	return result;
}

//fibBinToNum()
unsigned int BaseConverter::fibBinToNum(string fibToConv)
{
	//Defining the result
	unsigned int result = 0;

	//WHILE the length of the string is greater than the Fibonacci array length...
	while (fibToConv.length() > size)
	{
		//Generating more Fibonacci numbers
		generateMoreFibNums();
	}

	//FOR every character in the string...
	for (int num = fibToConv.length() - 1; num >= 0; num--)
	{
		//IF the character is '1'...
		if (fibToConv[num] == '1')
		{
			//Adding the corresponding value to the result
			result += *(fibSeq + fibToConv.length() - num - 1);
		}
	}

	//Returning the result;
	return result;
}

//b10BinToNum()
unsigned int BaseConverter::b10BinToNum(string b10ToConv)
{
	//Defining the result
	unsigned int result = 0;

	//FOR every character in the string...
	for (int num = b10ToConv.length() - 1; num >= 0; num--)
	{
		//IF the character is '1'...
		if (b10ToConv[num] == '1')
		{
			//Adding the corresponding value to the result
			result += (int)pow(2, b10ToConv.length() - num - 1);
		}
	}

	//Returning the result
	return result;
}

//generateMoreFibNums()
void BaseConverter::generateMoreFibNums()
{
	//Creating an old data array pointer
	int* oldData = new int[size];

	//Putting the Fibonacci array data into the old data array
	for (int num = 0; num < size; num++)
	{
		*(oldData + num) = *(fibSeq + num);
	}

	//Increasing the capacity of the Fibonacci array
	fibSeq = new int[size * 2];

	//Putting the old data back into the Fibonacci array
	for (int num = 0; num < size; num++)
	{
		*(fibSeq + num) = *(oldData + num);
	}

	//FOR as many times as the original size of the Fibonacci array...
	for (int num = size; num < size * 2; num++)
	{
		//Defining the next Fibonacci numbers
		*(fibSeq + num) = *(fibSeq + num - 1) + *(fibSeq + num - 2);
	}

	//Actually increasing the size variable
	size *= 2;

	//Deleting the old data array
	delete[] oldData;
}