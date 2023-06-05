#include "CPlace.h"
#include <iostream>

CPlace::CPlace(std::shared_ptr<CToyRobot> robot, std::shared_ptr<CTable> table, int posX, int posY, Face face) :
	m_robot(robot), m_table(table), m_posX(posX), m_posY(posY), m_face(face)
{

}


int CPlace::execute()
{
	return m_robot->PlaceInTable(m_posX, m_posY, m_face, m_table);
}
