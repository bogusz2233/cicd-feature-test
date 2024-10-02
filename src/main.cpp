#include <iostream>
#include "app_info.hpp"
#include "spdlog/spdlog.h"

int main()
{
    SPDLOG_INFO("Hello, World!");
    SPDLOG_INFO("App name: {}", app_info::AppInfo());
    return 0;
}