#include <string>

#include "util.h"
#include "WritingProcess.h"

using namespace std;

WritingProcess::WritingProcess() {
	this->file = "";
	this->equation = "";
}

void WritingProcess::execute() {

}

string WritingProcess::get_file() {
	return file;
}

void WritingProcess::set_file(string s_file) {
	file = s_file;
}

void WritingProcess::parse(string equation){
	parsed_equation = removeSpaces(equation) + "\n";
}

void WritingProcess::set_equation(string equation) {
	equation = equation;
}

string WritingProcess::get_equation() {
	return equation;
}