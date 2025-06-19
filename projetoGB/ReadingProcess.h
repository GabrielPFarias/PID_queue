#pragma once

#include <queue>
#include <string>

#include "Process.h"

using namespace std;

class ReadingProcess: public Process
{
public:
	ReadingProcess();
	ReadingProcess(queue<Process*>*, int);
	string get_file();
	void set_file(string);
private:
	int pid_counter;
	queue<Process*>* processQueue;
	string file;
	void execute() override;
};

