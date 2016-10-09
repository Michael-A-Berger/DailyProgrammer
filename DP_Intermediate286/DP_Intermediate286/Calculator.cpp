/*
	Context: https://www.reddit.com/r/dailyprogrammer/comments/55zdxx/

	Created by Michael Berger
*/

//Including the header
#include "Calculator.h";

//[Constructor]
Calculator::Calculator()
{
	//Defining the Fibonacci sequence
	fibSeq = new int[4];
	*fibSeq = 1;
	*(fibSeq + 1) = 1;
	*(fibSeq + 2) = 2;
	*(fibSeq + 3) = 3;
	sizeSeq = 4;
}

//[Destructor]
Calculator::~Calculator()
{
	//Deleting the Fibonacci sequence array pointer
	delete[] fibSeq;
}

//printFibSeq()
void Calculator::printFibSeq()
{
	//Printing out the method message
	cout << "The Fibonacci Sequence (so far):" << endl;

	//Printing out the Fibonacci sequence
	for (int num = 0; num < sizeSeq; num++)
	{
		cout << "\t" << (num + 1) << ":\t" << *(fibSeq + num) << endl;
	}

	//Leaving room for the other print functions
	cout << endl;
}

//giveZeckendorfRep()
string Calculator::giveZeckendorfRep(int input)
{
	//Creating the result variable
	string result;

	//WHILE the largest Fibonacci number is less than the input number...
	while (*(fibSeq + sizeSeq - 1) < input)
	{
		//Generate more Fibonacci numbers
		moreFibNumbers();
	}

	//Creating the Fibonacci sum variable
	int fibSum = 0;

	//FOR all of the Fibonacci numbers in the current sequence...
	for (int num = sizeSeq - 1; num >= 0; num--)
	{
		//IF the Fibonacci sum plus the current Fibonacci number is less than the input number...
		if (fibSum + *(fibSeq + num) <= input)
		{
			//IF the result string is greater than zero...
			if (result.length() > 0)
			{
				//Adding the plus to the result string
				result += " + ";
			}

			//Adding the current number to the Fibonacci sum
			fibSum += *(fibSeq + num);

			//Adding the number to the result string
			result += to_string(*(fibSeq + num));

			//Decrementing the iterator (ensures no following Fibonacci numbers)
			num--;
		}
	}

	//Returning the result
	return result;
}

//moreFibNumbers()
void Calculator::moreFibNumbers()
{
	//Creating a temporary array pointer
	int* temp = new int[sizeSeq * 2];

	//FOR every number in the sequence that's already calculated...
	for (int num = 0; num < sizeSeq; num++)
	{	
		//Putting the current Fibonacci number into the temporary array
		int numTemp = *(fibSeq + num);
		*(temp + num) = *(fibSeq + num);
	}

	//Setting the size variable to its appropriate size
	sizeSeq *= 2;

	//Redefining the Fibonacci sequence array pointer
	fibSeq = new int[sizeSeq];

	//Putting temporary data back into the Fibonacci sequence
	for (int num = 0; num < sizeSeq / 2; num++)
	{
		*(fibSeq + num) = *(temp + num);
	}

	//Deleting the temporary array
	delete[] temp;

	//FOR every Fibonacci number that's not calculated...
	for (int num = sizeSeq / 2; num < sizeSeq; num++)
	{
		//Calculating the current Fibonacci number
		int numTemp = *(fibSeq + num - 1) + *(fibSeq + num - 2);
		*(fibSeq + num) = *(fibSeq + num - 1) + *(fibSeq + num - 2);
	}
}