#include "finder_engine.h"

int main()
{
  //  time_t t1 = time(NULL);

    finder_engine find;

    std::string path_name;
    std::cout << "Enter app name: -> ";
    std::cin >> path_name;


    const std::string a = find.get_path_by_name(path_name);

    std::cout <<"===============================================\n" << a << std::endl;


  //time_t t2 = time(NULL);

      //std::cout << "==============Time================  -> " << t2 - t1 << std::endl;
    
    system("pause");

    return 0;
    
}