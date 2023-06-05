#include "CToyRobot.h"
#include "CError.h"
#include <memory>

CToyRobot::CToyRobot()
{
	m_face = Face::UNINITIALIZED;
	m_posX = 0;
	m_posY = 0;
	m_isPlaced = false;

	m_faceStringMap.insert({ Face::NORTH, "NORTH" });
	m_faceStringMap.insert({ Face::EAST, "EAST" });
	m_faceStringMap.insert({ Face::SOUTH, "SOUTH" });
	m_faceStringMap.insert({ Face::WEST, "WEST" });
}

bool CToyRobot::IsPlaced() 
{ 
	return m_isPlaced; 
};

std::string CToyRobot::FaceToFaceString(Face face)
{
	std::string faceString = "INVALID";

	for (auto it = m_faceStringMap.begin(); it != m_faceStringMap.end(); ++it)
	{
		if (it->first == face)
		{
			faceString = it->second;

			break;
		}
	}

	return faceString;
}

Face CToyRobot::FaceStringToFace(std::string faceString)
{
	Face face = Face::INVALID;

	for (auto it = m_faceStringMap.begin(); it != m_faceStringMap.end(); ++it)
	{
		if (it->second == faceString)
		{
			face = it->first;

			break;
		}
	}

	return face;
}

int CToyRobot::FaceLeft()
{
	if (m_face == Face::NORTH)
	{
		m_face = Face::WEST;
	}
	else if (m_face == Face::EAST)
	{
		m_face = Face::NORTH;
	}
	else if (m_face == Face::SOUTH)
	{
		m_face = Face::EAST;
	}
	else if (m_face == Face::WEST)
	{
		m_face = Face::SOUTH;
	}

	return TR_E_SUCESS;
}

int CToyRobot::FaceRight()
{
	if (m_face == Face::NORTH)
	{
		m_face = Face::EAST;
	}
	else if (m_face == Face::EAST)
	{
		m_face = Face::SOUTH;
	}
	else if (m_face == Face::SOUTH)
	{
		m_face = Face::WEST;
	}
	else if (m_face == Face::WEST)
	{
		m_face = Face::NORTH;
	}

	return TR_E_SUCESS;
}

int CToyRobot::ChangeDirection(Direction direction)
{
	if (!IsPlaced())
	{
		return TR_E_ROBOT_NOT_PLACED;
	}

	if (direction == Direction::LEFT)
	{
		return FaceLeft();
	}
	
	if (direction == Direction::RIGHT)
	{
		return FaceRight();
	}

	return TR_E_CHANGE_DIRECTION_FAILED;
}

int CToyRobot::MoveForward()
{
	if (!IsPlaced())
	{
		return TR_E_ROBOT_NOT_PLACED;
	}

	int newPosX = m_posX;
	int newPosY = m_posY;

	if (m_face == Face::NORTH)
	{
		newPosY++;
	}
	else if (m_face == Face::EAST)
	{
		newPosX++;
	}
	else if (m_face == Face::SOUTH)
	{
		newPosY--;
	}
	else if (m_face == Face::WEST)
	{
		newPosX--;
	}


	if (!m_table->IsLocationValid(newPosX, newPosY))
	{
		return TR_E_INVALID_LOCATION;
	}

	m_posX = newPosX;
	m_posY = newPosY;

	return TR_E_SUCESS;
}

int CToyRobot::PlaceInTable(int posX, int posY, Face face, std::shared_ptr<CTable> table)
{
	if (!table->IsLocationValid(posX, posY))
	{
		return TR_E_INVALID_LOCATION;
	}

	m_face = face;
	m_posX = posX;
	m_posY = posY;
	m_table = table;
	m_isPlaced = true;

	return TR_E_SUCESS;
}

void CToyRobot::GetPosition(int& posX, int& posY)
{
	posX = m_posX;
	posY = m_posY;
}

void CToyRobot::GetFace(Face& face)
{
	face = m_face;
}
