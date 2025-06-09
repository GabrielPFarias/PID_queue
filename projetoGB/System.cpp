#include "System.h"

using namespace std;

System::System() {
	this->file = "";
	this->option = 0;
}

void System::set_file(string s_file) {
	file = s_file;
}

string System::get_file() {
	return file;
}