#pragma once
#include "finder_engine.h"


int main()
{
    finder_engine find;

    std::string path_name;
    std::cout << "Enter app name: -> ";
    std::cin >> path_name;

    const std::string PATH = find.get_path_by_name(path_name);

    std::cout << "=================PATH TO FILE========================\n" << PATH << std::endl;

    system("pause");

    return 0;
    
}

