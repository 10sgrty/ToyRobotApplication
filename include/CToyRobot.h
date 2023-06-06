#pragma once
#include "CTable.h"
#include <memory>
#include <string>
#include <map>

class CTable;

enum class Direction
{
	UNINITIALIZED = -1,
	LEFT,
	RIGHT,
};

enum class Face
{
	INVALID = -2,
	UNINITIALIZED = -1,
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

class CToyRobot
{
private:
	int m_posX;
	int m_posY;
	Face m_face;
	bool m_isPlaced;
	std::shared_ptr<CTable> m_table;
	std::map<Face, std::string> m_faceStringMap;
	int FaceLeft();
	int FaceRight();

public:
	CToyRobot();

	bool IsPlaced();
	int ChangeDirection(const Direction& direction);
	int MoveForward();
	int PlaceInTable(const int& posX, const int& posY, const Face& face, const std::shared_ptr<CTable>& table);
	
	//int Report();
	void GetPosition(int& posX, int& posY);
	void GetFace(Face& face);

	std::string FaceToFaceString(const Face& face);
	Face FaceStringToFace(const std::string& faceString);
};


