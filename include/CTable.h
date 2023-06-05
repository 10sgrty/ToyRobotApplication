#pragma once

#ifndef __CTABLE_H__
#include "CToyRobot.h"
#include <memory>

#define TABLE_MAX_WIDTH		5
#define TABLE_MAX_HEIGHT	5

class CToyRobot;

class CTable
{
public:
	CTable(int width, int height);

	bool IsLocationValid(int x, int y);

private:
	int m_width;
	int m_height;
};

#endif /* __CTABLE_H__ */