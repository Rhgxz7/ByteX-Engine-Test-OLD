#include "sandbox.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {

    byx::Sandbox sandbox{};

    try {
        sandbox.run();  
    } catch(const std::exception &e) {
        std::cerr << "\nError" << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}