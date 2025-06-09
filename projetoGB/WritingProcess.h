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
private:
	string file;
	void execute();
	void parse();
};

