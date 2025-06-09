#include <string>

#include "ReadingProcess.h"

using namespace std;

ReadingProcess::ReadingProcess() {
	this->file = "";
}

void ReadingProcess::execute() {

}

string ReadingProcess::get_file() {
	return file;
}

void ReadingProcess::set_file(string s_file) {
	file = s_file;
}
