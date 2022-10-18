#include "sandbox.hpp"

namespace byx {

    void Sandbox::run() {

        glViewport(0,0,800,800);

        while(!byxWindow.shouldClose()) {
            glfwPollEvents();
        }

    }
}