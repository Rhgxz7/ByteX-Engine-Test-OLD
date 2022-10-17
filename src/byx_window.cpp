#include "byx_window.hpp"

namespace byx {

    ByxWindow::ByxWindow(int w, int h, std::string name) :
        width{w}, height{h}, windowName{name} {
            initWindow();
    }

    ByxWindow::~ByxWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void ByxWindow::initWindow() {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
         

    }

    bool ByxWindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }
}