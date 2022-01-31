#include "LogicalDrive.h"

std::vector<std::string> LogicalDrive::getListOfDrives()
{
    std::vector<std::string> arrayOfDrives;
    char* szDrives = new char[MAX_PATH]();
    if (GetLogicalDriveStringsA(MAX_PATH, szDrives))
    for (int i = 0; i < 100; i += 4)
        if (szDrives[i] != static_cast<char>(0))
            arrayOfDrives.push_back(std::string{ szDrives[i],szDrives[i + 1],szDrives[i + 2] });
    delete[] szDrives;
    return arrayOfDrives;
}