#pragma once
#include <vector>
#include <memory>
#include "CCommand.h"

class CController
{
private:
	std::shared_ptr<CToyRobot> m_robot;
	std::shared_ptr<CTable> m_table;
	std::vector<std::shared_ptr<CCommand>> m_commandList;

public:
	CController(std::shared_ptr<CToyRobot> robot, std::shared_ptr<CTable> table);
	int ProcessCommand(std::string commandString);
	int ProcessCommandList(std::vector<std::string> commandStringList);
	int ExecuteCommand();
	int ExecuteCommandList();


	int m_numParseFail;
	int m_numExecuteFail;
	void GetRobotState(int& posX, int& posY, Face& face);
};

