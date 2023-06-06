#include "CPlace.h"
#include <iostream>

CPlace::CPlace(const std::shared_ptr<CToyRobot>& robot, const std::shared_ptr<CTable>& table, const int& posX, const int& posY, const Face& face) :
	m_robot(robot), m_table(table), m_posX(posX), m_posY(posY), m_face(face)
{

}

int CPlace::execute()
{
	return m_robot->PlaceInTable(m_posX, m_posY, m_face, m_table);
}
