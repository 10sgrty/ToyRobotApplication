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
	CController(const std::shared_ptr<CToyRobot>& robot, const std::shared_ptr<CTable>& table);
	int ProcessCommand(const std::string& commandString);
	int ProcessCommandList(const std::vector<std::string>& commandStringList);
	int ExecuteCommand();
	int ExecuteCommandList();


	int m_numParseFail;
	int m_numExecuteFail;
	void GetRobotState(int& posX, int& posY, Face& face);
};

