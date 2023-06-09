#include "logger.hpp"
#include <iostream>
#include <thread>

void userLog1()
{
    Logger *loggerOne = Logger::getLogger();
    loggerOne->log("User One");
}

void userLog2()
{
    Logger *loggerTwo = Logger::getLogger();
    loggerTwo->log("User Two");
}

int main()
{
    std::thread t1(userLog1);
    std::thread t2(userLog2);

    t1.join();
    t2.join();
    return 0;
}