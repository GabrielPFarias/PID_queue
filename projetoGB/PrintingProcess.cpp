#include <queue>

#include "PrintingProcess.h"

using namespace std;

PrintingProcess::PrintingProcess() {}

PrintingProcess::PrintingProcess(queue<Process*>* processQueue) {
	this->file = "";
	this->processQueue = processQueue;
}

string PrintingProcess::get_file() {
	return file;
}

void PrintingProcess::set_file(string file) {
	this->file = file;
}


void PrintingProcess::execute() {}
