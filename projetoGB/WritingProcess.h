#pragma once

#include <string>

#include "Process.h"

using namespace std;

class WritingProcess: public Process
{
public:
	WritingProcess();
	void set_file(string);
	string get_file();
	void execute() override;
	void print() override;
	string toPoolFile() override;
	void set_equation(string);
	string get_equation();

private:
	string file;
	string equation;
};

