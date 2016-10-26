/*
	Context: https://www.reddit.com/r/dailyprogrammer/comments/50s3ax/

	Created by Michael Berger
*/
#pragma once

//Inclusions & Usings
#include <iostream>;
using std::cout;
using std::endl;

//The MS_Solver class
class MS_Solver
{
	//Public variables & methods
	public:
		MS_Solver();
		~MS_Solver();
		void solveOnce();

	//Private variables & methods
	private:
		void calcRisk();
		void calcHeuristics();
};