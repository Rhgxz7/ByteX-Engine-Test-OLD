#pragma once

#include "byx_window.hpp"

namespace byx {
    
    class Sandbox {

        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 800;

        void run();

        private:
        ByxWindow byxWindow{WIDTH, HEIGHT, "ByteX Engine"};
    };
}

