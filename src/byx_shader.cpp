#include "byx_shader.hpp"

namespace byx {

    std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
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