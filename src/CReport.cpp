#include "CReport.h"
#include "CError.h"
#include <iostream>

CReport::CReport(const std::shared_ptr<CToyRobot>& robot) :
	m_robot(robot)
{

}

void CReport::Report(const int& posX, const int& posY, const Face& face)
{	
	std::cout << "Output: " << posX << "," << posY << "," << m_robot->FaceToFaceString(face) << "\n";
}

int CReport::execute()
{
	int posX = 0;
	int posY = 0;
	Face face = Face::UNINITIALIZED;

	m_robot->GetPosition(posX, posY);
	m_robot->GetFace(face);
	Report(posX, posY, face);

	return TR_E_SUCESS;
}