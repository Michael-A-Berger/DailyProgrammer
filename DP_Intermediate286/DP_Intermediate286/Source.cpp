/*
	Context: https://www.reddit.com/r/dailyprogrammer/comments/55zdxx/

	Created by Michael Berger
*/

//Inclusions & Usings
#include "Calculator.h";
#include <iostream>;
using std::cout;
using std::endl;

//main()
int main()
{
	//Creating the calculator
	Calculator calc = Calculator();

	//Testing the Zeckendorf method
	cout << "5\t= " << calc.giveZeckendorfRep(5) << endl;
	cout << "120\t= " << calc.giveZeckendorfRep(120) << endl;
	cout << "34\t= " << calc.giveZeckendorfRep(34) << endl;
	cout << "88\t= " << calc.giveZeckendorfRep(88) << endl;
	cout << "90\t= " << calc.giveZeckendorfRep(90) << endl;
	cout << "320\t= " << calc.giveZeckendorfRep(320) << endl;

	//Returning zero
	return 0;
}