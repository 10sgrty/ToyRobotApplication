#include "CMoveForward.h"
#include <iostream>

CMoveForward::CMoveForward(const std::shared_ptr<CToyRobot>& robot, const std::shared_ptr<CTable>& table) :
	m_robot(robot), m_table(table)
{

}

int CMoveForward::execute()
{
	return m_robot->MoveForward();
}