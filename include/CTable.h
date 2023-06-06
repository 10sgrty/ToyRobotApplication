#pragma once
#include "CToyRobot.h"
#include <memory>

#define TABLE_MAX_WIDTH		5
#define TABLE_MAX_HEIGHT	5

class CToyRobot;

class CTable
{
public:
	CTable(const int& width, const int& height);

	bool IsLocationValid(const int& x, const int& y);

private:
	int m_width;
	int m_height;
};
