#pragma once
class Process
{
public:
	Process();
	int get_PID();
	void set_PID(int);
	virtual void execute() = 0;
protected:
	int PID;
};

