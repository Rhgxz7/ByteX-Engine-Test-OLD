#include "sandbox.hpp"
#include <math.h>

#include "byx_shader.hpp"
#include "byx_VAO.hpp"
#include "byx_VBO.hpp"
#include "byx_EBO.hpp"


namespace byx {

    void Sandbox::run() {

        GLfloat vertices[] = {

            -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
            0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
            0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
            -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, 
		    0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, 
		    0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f
        };

        GLuint indices[] = {
            0, 3, 5,
            3, 2, 4,
            5, 4, 1
        };

        glfwMakeContextCurrent(byxWindow.window);

        glViewport(0,0,800,800);

        Shader shaderProgram("gltriangle.vert", "gltriangle.frag");
	    
	    VAO VAO1;
	    VAO1.bind();

	    
	    VBO VBO1(vertices, sizeof(vertices));
	    
	    EBO EBO1(indices, sizeof(indices));

	    
	    VAO1.linkVBO(VBO1, 0);
	    
	    VAO1.unbind();
	    VBO1.unbind();
	    EBO1.unbind();
        


        while(!byxWindow.shouldClose()) {

            
		    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		
		    glClear(GL_COLOR_BUFFER_BIT);
		
		    shaderProgram.activate();
		
		    VAO1.bind();
		
		    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		
		    glfwSwapBuffers(byxWindow.window);
		
		    glfwPollEvents();
        }

        VAO1.destroy();
	    VBO1.destroy();
	    EBO1.destroy();
	    shaderProgram.destroy();
    }
}