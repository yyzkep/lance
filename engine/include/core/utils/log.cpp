#include "log.hpp"
#include <iostream>

Lance::Logger::Logger(std::string author, std::string message)
{
    std::cout << author << " " << message << std::flush;
}