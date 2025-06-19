#pragma once

#include "Process.h"

class PrintingProcess: public Process
{
public:
	PrintingProcess();
private:
	void execute() override;
};

