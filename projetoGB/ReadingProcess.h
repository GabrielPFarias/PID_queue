#pragma once

#include <queue>
#include <string>

#include "Process.h"

using namespace std;

class ReadingProcess: public Process
{
public:
	ReadingProcess();
	ReadingProcess(queue<Process*>*, int*);
	void execute() override;
	void print() override;
	string toPoolFile() override;
	string get_file();
	void set_file(string);
private:
	int* pid_counter;
	queue<Process*>* processQueue;
	string file;
};

