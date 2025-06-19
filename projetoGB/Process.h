#pragma once
class Process
{
public:
	Process();
	int get_PID();
	virtual void execute() = 0;
protected:
	int PID;
};

