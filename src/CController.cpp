#include "CController.h"
#include "CPlace.h"
#include "CMoveForward.h"
#include "CChangeDirection.h"
#include "CReport.h"
#include "CError.h"
#include <iostream>

CController::CController(std::shared_ptr<CToyRobot> robot, std::shared_ptr<CTable> table) :
    m_robot(robot), m_table(table), m_numParseFail(0), m_numExecuteFail(0)
{

}

int ParseCommandStringParameters(const std::string& commandString, int& posX, int& posY, Face& face)
{
    size_t start = 0;
    size_t end = 0;
    size_t len = 0;

    std::string posXString;
    std::string posYString;
    std::string faceString;

    try
    {
        start = commandString.find(' ', 0) + 1;
        end = commandString.find(',', 0);
        len = end - start;
        posXString = commandString.substr(start, len);
        posX = std::stoi(posXString);

        start = end + 1;
        end = commandString.find(',', start);
        len = end - start;
        posYString = commandString.substr(start, len);
        posY = std::stoi(posYString);

        start = end + 1;
        end = commandString.size();
        len = end - start;
        faceString = commandString.substr(start, len);

        if (faceString == "NORTH")
        {
            face = Face::NORTH;
        }
        else if (faceString == "EAST")
        {
            face = Face::EAST;
        }
        else if (faceString == "SOUTH")
        {
            face = Face::SOUTH;
        }
        else if (faceString == "WEST")
        {
            face = Face::WEST;
        }
        else
        {
            return TR_E_INVALID_FACE;
        }
    }
    catch (...)
    {
        return TR_E_INT_CONVERSION_FAILED;
    }

    return TR_E_SUCESS;
}

int CController::ProcessCommand(std::string commandString)
{
    size_t offset = commandString.find_first_of(' ');

    if (offset != commandString.npos)
    {
        if (commandString.substr(0, offset) == "PLACE")
        {
            int posX = 0;
            int posY = 0;
            Face face = Face::UNINITIALIZED;

            if (ParseCommandStringParameters(commandString, posX, posY, face) == 0)
            {
                m_commandList.push_back(std::make_shared<CPlace>(m_robot, m_table, posX, posY, face));
            }
            else
            {
                return TR_E_INVALID_COMMAND;
            }
        }
        else
        {
            return TR_E_INVALID_COMMAND;
        }
    }
    else
    {
        if (commandString == "MOVE")
        {
            m_commandList.push_back(std::make_shared<CMoveForward>(m_robot, m_table));
        }
        else if (commandString == "LEFT")
        {
            m_commandList.push_back(std::make_shared<CChangeDirection>(m_robot, Direction::LEFT));
        }
        else if (commandString == "RIGHT")
        {
            m_commandList.push_back(std::make_shared<CChangeDirection>(m_robot, Direction::RIGHT));
        }
        else if (commandString == "REPORT")
        {
            m_commandList.push_back(std::make_shared<CReport>(m_robot));
        }
        else
        {
            return TR_E_INVALID_COMMAND;
        }
    }

    return TR_E_SUCESS;
}

int CController::ProcessCommandList(std::vector<std::string> commandStringList)
{
    for (size_t i = 0; i < commandStringList.size(); i++)
    {
        if (ProcessCommand(commandStringList[i]) != TR_E_SUCESS)
        {
            m_numParseFail++;
        }
    }

    return TR_E_SUCESS;
}

int CController::ExecuteCommand()
{
    if (m_commandList.empty())
    {
            return TR_E_COMMAND_LIST_EMPTY;
    }

    return m_commandList.back()->execute();
}

int CController::ExecuteCommandList()
{
    for (size_t i = 0; i < m_commandList.size(); i++)
    {
        if (m_commandList[i]->execute() != TR_E_SUCESS)
        {
            m_numExecuteFail++;
        }
    }

    return TR_E_SUCESS;
}

void CController::GetRobotState(int& posX, int& posY, Face& face)
{
    m_robot->GetPosition(posX, posY);
    m_robot->GetFace(face);
}