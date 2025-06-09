#pragma once

#include <string>

#include "Process.h"

using namespace std;

class ComputingProcess: public Process
{
public:
	ComputingProcess();
private:
	float num1;
	float num2;
	string sign;
	float result;
	void execute();
	void parse(string);
};

