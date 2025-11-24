#ifndef WINDOW
#define WINDOW

#include <string>
struct GLFWwindow;
namespace Lance
{
// TODO: this
// window generation
class Window
{
public:
    Window(std::string title = "window", int width = 800, int height = 600);
    ~Window() = default;

    GLFWwindow *GetGLFWwindow();
    GLFWwindow *window;
};
} // namespace Lance

#endif /* WINDOW */
