#include "sandbox.hpp"

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