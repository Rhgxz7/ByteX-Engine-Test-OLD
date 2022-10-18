#pragma once

#include <GL/glew.h>
#include "byx_VBO.hpp"

namespace byx {

    class VAO
    {
        public:
        
            GLuint ID;
        
            VAO();

        
            void linkVBO(VBO& VBO, GLuint layout);
        
            void bind();
            void unbind();
            void destroy();
    };

}