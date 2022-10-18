#include "byx_window.hpp"

#include <iostream>
#include <stdexcept>

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

        glfwMakeContextCurrent(window); 

        if( window == NULL ){
            std::cerr << "\nError creating window" << std::endl;
            std::cerr << "\nYour GPU might not be compatible with OpenGL" << std::endl;
            glfwTerminate();
        }

        if (glewInit() != GLEW_OK) {
            std::cerr << "\n Failed to init GLEW\n" << std::endl;
        }
}

    bool ByxWindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }
}