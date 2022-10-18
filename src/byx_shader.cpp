#include "byx_shader.hpp"

namespace byx {

    std::string readShaderFile(const char* file) {
        std::ifstream in(file, std::ios::binary);

        if(in) {
            std::string read;
            in.seekg(0, std::ios::end);
            read.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&read[0], read.size());
            in.close();
            return(read);
        }
        throw(errno);
    }

    Shader::Shader(const char* vertexF, const char* fragmentF) {
        std::string vertexShaderFile = readShaderFile(vertexF);
        std::string fragmentShaderFile = readShaderFile(fragmentF);

        const char* vertexShaderSrc = vertexShaderFile.c_str();
        const char* fragmentShaderSrc = fragmentShaderFile.c_str();

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSrc, nullptr);
        glCompileShader(vertexShader);

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSrc, nullptr);
        glCompileShader(fragmentShader);  

        ID = glCreateProgram();

        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);     

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }


}