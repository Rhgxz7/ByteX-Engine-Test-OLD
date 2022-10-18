#include "sandbox.hpp"

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

namespace byx {

    void Sandbox::run() {

        glViewport(0,0,800,800);
        glClearColor(0.50f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(byxWindow.window);

        while(!byxWindow.shouldClose()) {
            glfwPollEvents();
        }

    }
}