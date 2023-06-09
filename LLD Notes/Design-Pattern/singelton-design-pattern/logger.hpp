#ifndef logger_h
#define logger_h

#include <iostream>
#include <mutex>

class Logger
{
private:
    static int createdInstance;
    static Logger *oneInstance;
    static std::mutex mtx;
    int a = 10;

    // Hide all the possible ways to create new instance of class from client
    Logger(); // private constructor
    // or other-ways to avoid overloading eg: copy constructor or = operator overloading
public:
    static Logger *getLogger();
    void log(std::string);
};

#endif