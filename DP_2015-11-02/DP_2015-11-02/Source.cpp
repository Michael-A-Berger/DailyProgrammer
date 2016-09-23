/*
	Context: https://www.reddit.com/r/dailyprogrammer/comments/3r7wxz/

	Created by Michael Berger
*/

//Inclusions & Usings
#include <iostream>;
#include <string>;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

//main()
int main()
{
	//Defining the number
	int number = INT_MIN;

	//Displaying the title
	cout << "====== A Game of Threes ======" << endl << endl;

	//Getting a number from the user
	while (number == INT_MIN)
	{
		//Setting the number to zero
		number = 0;

		//Telling the user to input a number
		cout << "Input a number (less than 4 billion, please): ";

		//Putting the input into a dummy string
		string dummy;
		getline(cin, dummy);

		//FOR each character in the string
		for (int num = 0; num < dummy.length(); num++)
		{
			//IF the current character is NOT a number...
			if (dummy[num] < '0'   ||   dummy[num] > '9')
			{
				//Printing that the user didn't input a valid number
				cout << "That's not a valid number." << endl;

				//Setting the number to the minimum integer value
				number = INT_MIN;

				//Exiting the loop early
				num = dummy.length();
			}
			//ELSE... (the character is a number)
			else
			{
				//Translating the current character into the number
				number += (dummy[num] - '0') * pow(10, dummy.length() - 1 - num);
			}
		}
	}
	cout << endl;

	//WHILE the chosen number is not one...
	while (number != 1)
	{
		//Printing out the number
		cout << number;

		//IF the modulus of the number by three is two...
		if (number % 3 == 2)
		{
			//Printing out the "+1" notifier
			cout << "\t+1";
			
			//Incrementing the number
			number++;
		}
		//ELSE IF the modulus of the number by three is one...
		else if (number % 3 == 1)
		{
			//Printing out the "-1" notifier
			cout << "\t-1";

			//Decrementing the number
			number--;
		}
		//ELSE... (the number is already divisible by three)
		else
		{
			//Printing out the "0" notifier
			cout << "\t 0";
		}

		//Printing out the newline
		cout << endl;

		//Dividing the number by three
		number /= 3;
	}

	//Finally printing out the one
	cout << number << endl << endl;

	//Returning zero
	return 0;
}