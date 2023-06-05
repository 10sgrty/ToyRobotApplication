# Toy Robot Application
## Description
This application simulates the movement of a Toy Robot withing the confines of the table. Its movement and actions is also limited as specified in the requirements.
## Set-up
### IDE
Microsoft Visual Studio Community 2019/Microsoft Visual Studio Community 2022
### Windows SDK Version
10.0.19041.0
### Platform Toolset
Visual Studio 2019 (v142)
### Steps
1. Download the IDE from [here](https://visualstudio.microsoft.com/vs/community/).
2. Make sure the correct Windows SDK Version and Platform Toolset are included in the installation, its checkboxes must be ticked. Google Test package is already included in the default installation.
3. Grab the codes by typing the following in the command line. Make sure that your system has Git ready.
```
  $ git clone -b develop https://github.com/10sgrty/ToyRobotApplication.git
```
4. Open the solutions file in the IDE. Select between the application and test project. hit build and run.

For Microsoft Visual Studio Community 2022, when the IDE prompts to upgrade the project files for a later version, choose "No Upgrade", use the correct Windows SDK Version and Platform Toolset specified above.
## Testing
This application uses a separate project for testing. The Google Test package was used to test the application.
## Requirements
The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.
The console application will read the commands of the following form:
```
PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT
```
PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST. The origin (0,0) can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The application should discard all commands in the sequence until a valid PLACE command has been executed. MOVE will move the toy robot one unit forward in the direction it is currently facing. LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the robot. REPORT will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient. A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands. Input command on the command line, then press enter. Do the same for each subsequent commands. To quit the application, input the command below.
```
:q
```
## Constraints
The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot. Any move that would cause the robot to fall must be ignored.
## Examples
### Example A
```
PLACE 0,0,NORTH
MOVE
REPORT
Output: 0,1,NORTH
```
### Example B
```
PLACE 0,0,NORTH
LEFT
REPORT
Output: 0,0,WEST
```
### Example C
```
PLACE 1,2,EAST
MOVE
MOVE
LEFT
MOVE
REPORT
Output: 3,3,NORTH
```
