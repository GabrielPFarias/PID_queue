#pragma once

#include <string>

#include "Process.h"

using namespace std;

class ReadingProcess: public Process
{
public:
	ReadingProcess();
	string get_file();
	void set_file(string);
private:
	string file;
	void execute();
};

