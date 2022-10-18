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

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
         

    }

    bool ByxWindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }
}