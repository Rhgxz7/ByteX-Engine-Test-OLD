#include "byx_shader.hpp"

namespace byx {

    const GLchar* get_file_contents(const GLchar* pathToFile)
{
    std::string content;
    std::ifstream fileStream(pathToFile, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << pathToFile << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    std::cout << "'" << content << "'" << std::endl;
    return content.c_str();
}

    Shader::Shader(const char* vertexF, const char* fragmentF) {
        std::string vertexShaderFile = get_file_contents(vertexF);
        std::string fragmentShaderFile = get_file_contents(fragmentF);

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
    
    void Shader::activate() {
        glUseProgram(ID);
    }

    void Shader::destroy() {
        glDeleteProgram(ID);
    }

}