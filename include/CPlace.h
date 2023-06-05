#pragma once
#include "CCommand.h"
#include "CToyRobot.h"
#include "CTable.h"
#include <memory>

class CPlace :
    public CCommand
{
public:
    CPlace(std::shared_ptr<CToyRobot> robot, std::shared_ptr<CTable> table, int posX, int posY, Face face);
    virtual int execute();

private:
    std::shared_ptr<CToyRobot> m_robot;
    std::shared_ptr<CTable> m_table;
    int m_posX;
    int m_posY;
    Face m_face;
};
