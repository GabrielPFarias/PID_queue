#pragma once

#include <string>

#include "Process.h"

using namespace std;

class ComputingProcess: public Process
{
public:
	ComputingProcess();
	void execute() override;
	void parse(string);
private:
	double num1;
	double num2;
	string sign;
	double result;
};

