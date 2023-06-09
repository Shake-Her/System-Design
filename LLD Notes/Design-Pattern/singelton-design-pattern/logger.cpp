#include "logger.hpp"
#include <iostream>

int Logger::createdInstance = 0;
Logger *Logger::oneInstance = nullptr;
std::mutex Logger::mtx;

Logger::Logger()
{
    createdInstance++;
    std::cout << "CreatedInstance: " << createdInstance << std::endl;
}

Logger *Logger::getLogger()
{
    // double checking because locks are expensive
    if (oneInstance == nullptr)
    {
        mtx.lock();
        if (oneInstance == nullptr)
            oneInstance = new Logger();
        mtx.unlock();
    }
    return oneInstance;
}

void Logger::log(std::string userNo)
{
    std::cout << userNo << std::endl;
}
