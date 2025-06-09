#pragma once
class Process
{
public:
	Process();
	int get_PID();
protected:
	int PID;
	virtual void execute();

};

