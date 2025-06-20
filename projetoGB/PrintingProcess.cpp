#include <iostream>
#include <queue>

#include "PrintingProcess.h"

using namespace std;

PrintingProcess::PrintingProcess() {}

PrintingProcess::PrintingProcess(queue<Process*>* processQueue) {
	this->processQueue = processQueue;
}

void PrintingProcess::execute() {
	queue<Process*> processQueueTemp = *processQueue;
	while (!processQueueTemp.empty()) {
		Process* tempProcess = processQueueTemp.front();
		tempProcess->print();
		processQueueTemp.pop();
	}
}

void PrintingProcess::print() {
	cout << "Tipo: " << "PrintingProcess" << "  PID: " << PID << endl;
}

string PrintingProcess::toPoolFile() {
	return "PrintingProcess;" + to_string(PID) + ";";
}