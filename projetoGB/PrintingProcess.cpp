#include <queue>

#include "PrintingProcess.h"

using namespace std;

PrintingProcess::PrintingProcess() {}

PrintingProcess::PrintingProcess(queue<Process*>* processQueue) {
	this->processQueue = processQueue;
}

void PrintingProcess::execute() {}
