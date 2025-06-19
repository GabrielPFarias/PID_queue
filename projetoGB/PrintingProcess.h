#pragma once

#include <queue>

#include "Process.h"

class PrintingProcess: public Process
{
public:
	PrintingProcess();
	PrintingProcess(queue<Process*>*);
private:
	
private:
	queue<Process*>* processQueue;
	void execute() override;
};

