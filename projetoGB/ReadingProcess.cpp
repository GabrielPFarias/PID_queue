#include <fstream>
#include <queue>
#include <string>
#include <vector>

#include "ComputingProcess.h"
#include "ReadingProcess.h"

using namespace std;

ReadingProcess::ReadingProcess() {}

ReadingProcess::ReadingProcess(queue<Process*>* processQueue, int pid_counter) {
	this->file = "";
	this->processQueue = processQueue;
	this->pid_counter = pid_counter;
}

void ReadingProcess::execute() {
	ifstream iMyFile(file);
	vector<string> lines;

	string line;
	while (getline(iMyFile, line)) {
		lines.push_back(line);
	}
	iMyFile.close();

	for (size_t i = 0; i < lines.size(); i++) {
		ComputingProcess* computingProcess = new ComputingProcess();
		computingProcess->set_equation(lines[i]);
		computingProcess->set_PID(pid_counter);
		pid_counter++;

		processQueue->push(computingProcess);
	}

	ofstream oMyFile(file);
	oMyFile.clear();
	oMyFile.close();
}

string ReadingProcess::get_file() {
	return file;
}

void ReadingProcess::set_file(string file) {
	this->file = file;
}
