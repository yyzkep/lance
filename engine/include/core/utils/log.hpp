#ifndef LOG
#define LOG
#include <string>

namespace Lance
{
class Logger
{
public:
    Logger(std::string author /* from what function it came from.*/ = "[Lance::Engine]", std::string message /*what to log*/ = "");
};
} // namespace Lance

#endif /* LOG */
