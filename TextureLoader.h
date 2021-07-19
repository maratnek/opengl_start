#pragma once
#include <string>
#include <GL/glew.h>

class TextureLoader
{
private:
    /* data */
public:
    TextureLoader(/* args */);
    ~TextureLoader();
    GLuint getTextureID(std::string textFileName);
};

