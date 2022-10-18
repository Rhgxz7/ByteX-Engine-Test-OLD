#include "sandbox.hpp"
#include <math.h>

// Vertex Shader source code


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

        glViewport(0,0,800,800);

        GLuint VAO, VBO, EBO;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO); 
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


        while(!byxWindow.shouldClose()) {

            glClearColor(0.50f, 0.13f, 0.17f, 1.0f);

            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shaderProgram);

            glBindVertexArray(VAO);

            glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

            glfwSwapBuffers(byxWindow.window);

            glfwPollEvents();
        }

        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glDeleteProgram(shaderProgram);

    }
}