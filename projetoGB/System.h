#pragma once

#include <queue>
#include <string>

#include "Process.h"

using namespace std;

class System {
public:
	System();
	void set_computation_file(string);
	string get_computation_file();
	void run();

private:
	string computation_file;
	int pid_counter;
	queue<Process*> processQueue;
	void createProcess();
	void executeNextProcess();
	void executeSpecificProcess();
	void saveInFile();
	void retrieveFromFile();
};