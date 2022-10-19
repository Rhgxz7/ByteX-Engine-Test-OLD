#pragma once

#include <GL/glew.h>

namespace byx {

    class VBO {
        public:

	    GLuint ID;
	
	    VBO(GLfloat* vertices, GLsizeiptr size);
	
	    void bind();
	    void unbind();
	    void destroy();
};

}