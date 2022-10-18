#pragma once

#include<GL/glew.h>

namespace byx {

        class EBO {
            public:

            GLuint ID;
        
            EBO(GLuint* indices, GLsizeiptr size);

        
            void bind();
            void unbind();
            void dstroy();
        };

}

