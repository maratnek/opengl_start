#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh/Mesh.h"
#include "ShaderLoader.h"
#include "Camera.h"

class LightRenderer
{
private:
    Camera* camera;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    glm::vec3 position, color;
    GLuint vbo, ebo, vao, program;
public:
    LightRenderer(MeshType meshType, Camera* camera);

    void draw();
    void setPosition(glm::vec3 _pos);
    void setColor(glm::vec3 _color);
    void setProgram(GLuint _program);

    glm::vec3 getPosition();
    glm::vec3 getColor();
};

