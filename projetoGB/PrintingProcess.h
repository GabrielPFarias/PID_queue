#pragma once

#include <queue>
#include <string>

#include "Process.h"

using namespace std;

class PrintingProcess: public Process
{
public:
	PrintingProcess();
	PrintingProcess(queue<Process*>*);
	string get_file();
	void set_file(string);

private:
	string file;
	queue<Process*>* processQueue;
	void execute() override;
};

