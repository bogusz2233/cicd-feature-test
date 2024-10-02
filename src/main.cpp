#include <iostream>
#include "app_info.hpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "App name: " << app_info::AppInfo() << std::endl;
    return 0;
}