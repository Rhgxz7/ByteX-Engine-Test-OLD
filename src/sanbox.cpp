#include "sandbox.hpp"

namespace byx {

    void Sandbox::run() {
        while(!byxWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}