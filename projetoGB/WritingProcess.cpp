#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "util.h"
#include "WritingProcess.h"

using namespace std;

WritingProcess::WritingProcess() {
	this->file = "";
	this->equation = "";
}

void WritingProcess::execute() {
	ifstream iMyFile(file);
	vector<string> lines;

	string line;
	while (getline(iMyFile, line)) {
		lines.push_back(line);
	}
	iMyFile.close();

	lines.push_back(equation);

	ofstream oMyFile(file);
	for (size_t i = 0; i < lines.size(); i++) {
		oMyFile << lines[i] << endl;
	}
	oMyFile.close();

}

string WritingProcess::get_file() {
	return file;
}

void WritingProcess::set_file(string file) {
	this->file = file;
}

void WritingProcess::set_equation(string equation) {
	this->equation = equation;
}

string WritingProcess::get_equation() {
	return equation;
}

void WritingProcess::print() {
	cout << "Tipo: " << "WritingProcess" << "  PID: " << get_PID() << "  Equation: " << get_equation() << endl;
}

string WritingProcess::toPoolFile() {
	return "WritingProcess;" + to_string(PID) + ";" + equation;
}