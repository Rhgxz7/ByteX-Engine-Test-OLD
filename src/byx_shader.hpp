#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cerrno>

#include <GL/glew.h>

std::string get_file_contents(const char* file);

namespace byx {

    class Shader {

        public:  
        GLuint ID;
        Shader(const char* vertexF, const char* fragmentF);

        void activate();
        void destroy();

    };
}