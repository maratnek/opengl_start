#pragma once

#include <GL/glew.h>
#include <string>

class ShaderLoader
{
private:
    /* data */
    std::string readShader(const char *filename);
    GLuint createShader(GLenum shaderType, std::string source, const char* shaderName);
public:
    // ShaderLoader();
    // ~ShaderLoader();
    GLuint createProgram(const char* vertexShaderFilename, const char* fragmentShaderFilename);
};
