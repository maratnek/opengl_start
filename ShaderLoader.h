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
    ShaderLoader(/* args */);
    ~ShaderLoader();
    GLuint createProgramm(const char* vertexShaderFilename, const char* fragmentShaderFilename);
};

ShaderLoader::ShaderLoader(/* args */)
{
}

ShaderLoader::~ShaderLoader()
{
}
