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
	int num1;
	int num2;
	string sign;
	float result;
};

