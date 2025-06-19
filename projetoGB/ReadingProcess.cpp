#include <queue>
#include <string>

#include "ReadingProcess.h"

using namespace std;

ReadingProcess::ReadingProcess() {}

ReadingProcess::ReadingProcess(queue<Process*>* processQueue) {
	this->file = "";
	this->processQueue = processQueue;
}

void ReadingProcess::execute() {

}

string ReadingProcess::get_file() {
	return file;
}

void ReadingProcess::set_file(string s_file) {
	file = s_file;
}
