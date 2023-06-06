#pragma once
#include "CCommand.h"
#include "CToyRobot.h"
#include <memory>

class CReport :
    public CCommand
{
public:
    CReport(const std::shared_ptr<CToyRobot>& robot);
    virtual int execute();

private:
    std::shared_ptr<CToyRobot> m_robot;

    void Report(const int& posX, const int& posY, const Face& face);
};

