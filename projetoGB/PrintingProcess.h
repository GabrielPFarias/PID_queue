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

private:
	queue<Process*>* processQueue;
};

