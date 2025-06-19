#include "Process.h"

Process::Process() {
	this->PID = 0;
}

int Process::get_PID() {
	return PID;
}

void Process::set_PID(int pid) {
	PID = pid;
}