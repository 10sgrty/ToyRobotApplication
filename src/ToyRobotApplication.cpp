#include "CController.h"
#include "CToyRobot.h"
#include "CTable.h"
#include "CCommand.h"
#include "CError.h"
#include <iostream>
#include <string>
#include <vector>


void DisplayHelp()
{
    std::cout << "Toy Robot Application\n";
    std::cout << "List of commands:\n";
    std::cout << "PLACE X,Y,Z\n";
    std::cout << "  Place the robot in to the table, where X is the position in x-axis and Y is the position in y-axis of the table.\n";
    std::cout << "  The X and Y values should not exceed the size of the table. The possible values for Z are NORTH, EAST, SOUTH and WEST.\n";
    std::cout << "  Example:\n    PLACE 0,0,NORTH\n";

    std::cout << "MOVE\n";
    std::cout << "  Move the robot forward in its current facing direction. Robot need to be placed on the table first.\n";

    std::cout << "LEFT\n";
    std::cout << "  Robot turns left, the direction it is facing will change. Robot need to be placed on the table first.\n";

    std::cout << "RIGHT\n";
    std::cout << "  Robot turns right, the direction it is facing will change. Robot need to be placed on the table first.\n";

    std::cout << "REPORT\n";
    std::cout << "  Display the robot's current position on the table snd the diretion it is facing. Robot need to be placed on the table first.\n";
    std::cout << "*To quit, use the command \":q\". \n\n";
    std::cout << "Please enter a command:\n";
}

int main(int argc, char* argv[])
{
    
    std::shared_ptr<CToyRobot> robot = std::make_shared<CToyRobot>();
    std::shared_ptr<CTable> table = std::make_shared<CTable>(TABLE_MAX_WIDTH, TABLE_MAX_HEIGHT);
    CController controller(robot, table);

    DisplayHelp();

    try
    {
        while (1)
        {
            std::string commandString;

            std::getline(std::cin, commandString);

            if (commandString == ":q")
            {
                break;
            }

            if (controller.ProcessCommand(commandString) == 0)
            {
                controller.ExecuteCommand();
            }
        }
    }
    catch (...)
    {
        return TR_E_GENERAL_ERROR;
    }


    return TR_E_SUCESS;
}
