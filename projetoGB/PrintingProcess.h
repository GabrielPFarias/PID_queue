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
	void execute() override;
	void print() override;
	string toPoolFile() override;
	string get_file();
	void set_file(string);

private:
	string file;
	queue<Process*>* processQueue;
};

