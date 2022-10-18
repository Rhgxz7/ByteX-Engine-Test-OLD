#pragma once 

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define GLEW_STATIC
#include <GL/glew.h>   


#include <string>

namespace byx {

    class ByxWindow {

        public:
        ByxWindow(int w, int h, std::string name);
        ~ByxWindow();

        bool shouldClose();

        private:

        void initWindow();

        const int width;
        const int height;
        std::string windowName;
        GLFWwindow *window;

    };
}