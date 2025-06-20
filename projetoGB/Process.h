#pragma once

#include <string>

using namespace std;

class Process
{
public:
	Process();
	int get_PID();
	void set_PID(int);
	virtual void execute() = 0;
	virtual void print() = 0;
	virtual string toPoolFile() = 0;
protected:
	int PID;
};

