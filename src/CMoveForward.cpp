#include "CMoveForward.h"
#include <iostream>

CMoveForward::CMoveForward(std::shared_ptr<CToyRobot> robot, std::shared_ptr<CTable> table) :
	m_robot(robot), m_table(table)
{

}


int CMoveForward::execute()
{
	return m_robot->MoveForward();
}