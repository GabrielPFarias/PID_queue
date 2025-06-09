#include <string>

#include "WritingProcess.h"

using namespace std;

WritingProcess::WritingProcess() {
	this->file = "";
}

void WritingProcess::execute() {

}

string WritingProcess::get_file() {
	return file;
}

void WritingProcess::set_file(string s_file) {
	file = s_file;
}

void WritingProcess::parse(){}