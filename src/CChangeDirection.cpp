#include "CChangeDirection.h"
#include <iostream>

CChangeDirection::CChangeDirection(const std::shared_ptr<CToyRobot>& robot, const Direction& direction) :
	m_robot(robot), m_direction(direction)
{

}

int CChangeDirection::execute()
{
	return m_robot->ChangeDirection(m_direction);
}