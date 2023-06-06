#pragma once
#include "CCommand.h"
#include "CToyRobot.h"
#include "CTable.h"
#include <memory>

class CMoveForward :
    public CCommand
{
public:
    CMoveForward(const std::shared_ptr<CToyRobot>& robot, const std::shared_ptr<CTable>& table);
    virtual int execute();

private:
    std::shared_ptr<CToyRobot> m_robot;
    std::shared_ptr<CTable> m_table;
};

