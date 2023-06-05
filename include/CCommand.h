#pragma once
#include "CToyRobot.h"

class CCommand
{
public:
	virtual ~CCommand() { }
	virtual int execute() = 0;
};

