#include "CTestFixture.h"
#include "CController.h"

CTestFixture::CTestFixture() :
    m_posX(0), m_posY(0), m_face(Face::UNINITIALIZED)
{

}

void CTestFixture::SetUp()
{
    std::shared_ptr<CToyRobot> robot = std::make_shared<CToyRobot>();
    std::shared_ptr<CTable> table = std::make_shared<CTable>(TABLE_MAX_WIDTH, TABLE_MAX_HEIGHT);
    m_controller = std::make_shared<CController>(robot, table);

    std::vector<std::string> commandStringList = {
        "PLACE 0,0,NORTH",
        "LEFT",
    };
}
