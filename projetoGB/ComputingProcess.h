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
	float num1;
	float num2;
	string sign;
	float result;
};

