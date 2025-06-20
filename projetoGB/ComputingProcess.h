#pragma once

#include <string>

#include "Process.h"

using namespace std;

class ComputingProcess: public Process
{
public:
	ComputingProcess();
	void execute() override;
	void print() override;
	string toPoolFile() override;
	void parse();
	string get_equation();
	void set_equation(string);
private:
	string equation;
	double num1;
	double num2;
	string sign;
	double result;
};

