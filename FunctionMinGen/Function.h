#pragma once
#include <vector>
#include <iostream>
#include "gealib/gealib.h"

#define McCormick 1
#define Himmelblau 2
#define Matyas 3

class Function {

	//Function pointer
	ftype(*m_function)(vector<ftype>& v) = Function::McCormick_;

	//Coordinates with coresponding ranges
	std::vector<gealib::parameter> m_params;

	//Mutation rate parameter
	double m_mutationRate;

	//Static predefined functions taken from 
	//https://en.wikipedia.org/wiki/Test_functions_for_optimization
	static ftype McCormick_	(vector <ftype> & v);
	static ftype Himmelblau_(vector <ftype> & v);
	static ftype Matyas_	(vector <ftype> & v);

public:

	//Constructor
	Function(unsigned short function, std::vector<double> precision, double mutationRate );

	//Run function
	void run(size_t iterations, size_t showProgress, std::vector<double>* outcome);
	std::vector<double> run(size_t iterations, size_t showProgress);

	void print(std::vector<double> * outcome);

};

