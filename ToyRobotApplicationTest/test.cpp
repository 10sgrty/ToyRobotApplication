#include "CController.h"
#include "CTestFixture.h"
#include "gtest/gtest.h"

TEST_F(CTestFixture, SimpleTestA)
{
    std::vector<std::string> commandStringList = {
     "PLACE 0,0,NORTH",
     "MOVE",
    };

    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 0);
    EXPECT_EQ(m_posY, 1);
    EXPECT_EQ(m_face, Face::NORTH);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}

TEST_F(CTestFixture, SimpleTestB)
{
    std::vector<std::string> commandStringList = {
        "PLACE 0,0,NORTH",
        "LEFT",
    };

    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 0);
    EXPECT_EQ(m_posY, 0);
    EXPECT_EQ(m_face, Face::WEST);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}

TEST_F(CTestFixture, SimpleTestC)
{
    std::vector<std::string> commandStringList = {
        "PLACE 1,2,EAST",
        "MOVE",
        "MOVE",
        "LEFT",
        "MOVE",
    };

    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 3);
    EXPECT_EQ(m_posY, 3);
    EXPECT_EQ(m_face, Face::NORTH);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}

TEST_F(CTestFixture, TurnAroundA)
{
    std::vector<std::string> commandStringList = {
        "PLACE 2,2,SOUTH",
        "LEFT",
        "LEFT",
        "LEFT",
    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 2);
    EXPECT_EQ(m_posY, 2);
    EXPECT_EQ(m_face, Face::WEST);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}

TEST_F(CTestFixture, TurnAroundB)
{
    std::vector<std::string> commandStringList = {
        "PLACE 2,2,SOUTH",
        "RIGHT",
        "RIGHT",
        "RIGHT",
        "RIGHT",
    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 2);
    EXPECT_EQ(m_posY, 2);
    EXPECT_EQ(m_face, Face::SOUTH);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}

TEST_F(CTestFixture, TurnAroundC)
{
    std::vector<std::string> commandStringList = {
        "PLACE 2,2,NORTH",
        "RIGHT",
        "RIGHT",
        "RIGHT",
        "RIGHT",
        "LEFT",
        "LEFT",
    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 2);
    EXPECT_EQ(m_posY, 2);
    EXPECT_EQ(m_face, Face::SOUTH);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}

TEST_F(CTestFixture, GoAroundA)
{
    std::vector<std::string> commandStringList = {
        "PLACE 0,0,EAST",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "LEFT",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "LEFT",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "LEFT",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",

    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 0);
    EXPECT_EQ(m_posY, 0);
    EXPECT_EQ(m_face, Face::SOUTH);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}

TEST_F(CTestFixture, GoAroundB)
{
    std::vector<std::string> commandStringList = {
        "PLACE 0,0,NORTH",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "RIGHT",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "RIGHT",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "RIGHT",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",

    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 0);
    EXPECT_EQ(m_posY, 0);
    EXPECT_EQ(m_face, Face::WEST);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}


TEST_F(CTestFixture, RobotFallTestA)
{
    std::vector<std::string> commandStringList = {
        "PLACE 0,4,EAST",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
    };

    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 4);
    EXPECT_EQ(m_posY, 4);
    EXPECT_EQ(m_face, Face::EAST);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 2);
}

TEST_F(CTestFixture, RobotFallTestB)
{
    std::vector<std::string> commandStringList = {
        "PLACE 3,1,NORTH",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE",
    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 3);
    EXPECT_EQ(m_posY, 4);
    EXPECT_EQ(m_face, Face::NORTH);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 3);
}

TEST_F(CTestFixture, RobotFallTestC)
{
    std::vector<std::string> commandStringList = {
        "PLACE 0,0,NORTH",
        "MOVE",
        "PLACE 1,1,NORTH",
        "PLACE 2,2,NORTH",
        "MOVE",
        "MOVE",
        "PLACE 3,3,NORTH",
        "PLACE 4,4,NORTH",
        "LEFT",
        "MOVE",
        "RIGHT",
        "MOVE",
    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 3);
    EXPECT_EQ(m_posY, 4);
    EXPECT_EQ(m_face, Face::NORTH);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 1);
}

TEST_F(CTestFixture, InvalidCommandStringRecover)
{
    std::vector<std::string> commandStringList = {
        "PLACING 0,0,NORTH", // Invalid
        "PLACE 1,1,NORTH",
        "PLACE 1,1,ANY", // Invalid
        "PLACE 2,2,NORTH",
        "MOVE",
        "MOVE",
        "TELEPORT", // Invalid
        "PLACE 3,3,NORTH",
        "PLACE 4,4,NORTH",
        "LEFT",
        "MOVE",
        "RIGHT",
        "MOVE AWAY", // Invalid
        "LEFT",
    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 3);
    EXPECT_EQ(m_posY, 4);
    EXPECT_EQ(m_face, Face::WEST);

    EXPECT_EQ(m_controller->m_numParseFail, 4);
    EXPECT_EQ(m_controller->m_numExecuteFail, 0);
}

TEST_F(CTestFixture, ExecuteFailRecover)
{
    std::vector<std::string> commandStringList = {
        "PLACE 1,1,NORTH",
        "PLACE 2,2,NORTH",
        "MOVE",
        "MOVE",
        "PLACE 5,5,NORTH", // Fail
        "PLACE 3,3,NORTH",
        "PLACE 4,4,NORTH",
        "LEFT",
        "MOVE",
        "RIGHT",
        "LEFT",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE", // Fail
        "RIGHT",
    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 0);
    EXPECT_EQ(m_posY, 4);
    EXPECT_EQ(m_face, Face::NORTH);

    EXPECT_EQ(m_controller->m_numParseFail, 0);
    EXPECT_EQ(m_controller->m_numExecuteFail, 2);
}

TEST_F(CTestFixture, FirstCommandFail)
{
    std::vector<std::string> commandStringList = {
        "LEFT", // Fail
        "MOVE", // Fail
        "RIGHT", // Fail
        "PLACING 1,1,NORTH", // Invalid
        "PLACE 1,1,NORTH",
        "PLACE 2,2,NORTH",
        "MOVE",
        "MOVE",
        "PLACE 5,5,NORTH", // Fail
        "PLACE 3,3,NORTH",
        "PLACE 4,4,NORTH",
        "LEFT",
        "MOVE",
        "RIGHT",
        "LEFT",
        "MOVE",
        "MOVE",
        "MOVE",
        "MOVE", // Fail
        "RIGHT",
    };


    m_controller->ProcessCommandList(commandStringList);
    m_controller->ExecuteCommandList();

    m_controller->GetRobotState(m_posX, m_posY, m_face);

    EXPECT_EQ(m_posX, 0);
    EXPECT_EQ(m_posY, 4);
    EXPECT_EQ(m_face, Face::NORTH);

    EXPECT_EQ(m_controller->m_numParseFail, 1);
    EXPECT_EQ(m_controller->m_numExecuteFail, 5);
}
