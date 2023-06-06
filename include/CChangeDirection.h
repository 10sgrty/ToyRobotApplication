#pragma once
#include "CCommand.h"
#include "CToyRobot.h"
#include "CTable.h"
#include <memory>

class CChangeDirection :
    public CCommand
{
public:
    CChangeDirection(const std::shared_ptr<CToyRobot>& robot, const Direction& direction);
    virtual int execute();

private:
    std::shared_ptr<CToyRobot> m_robot;
    Direction m_direction;
};

