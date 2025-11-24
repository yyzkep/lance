#include "../../engine/include/lance.hpp"
#include <iostream>
#include <string>

int main()
{
    Lance::Application app;
    app.init();
    app.run();
    app.shutdown();
    return 0;
}
