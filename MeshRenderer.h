#pragma once

#include <vector>

#include "Camera.h"
#include "LightRenderer.h"
#include "Mesh/Mesh.h"

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <btBulletDynamicsCommon.h>

class MeshRenderer
{
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    glm::mat4 modelMatrix;
    Camera* camera;
    glm::vec3 position, scale;
    GLuint vao, vbo, ebo, texture, program;
    btRigidBody *rigidBody;
public:
    MeshRenderer(MeshType modelType, Camera* _camera, btRigidBody* _rigid);
    ~MeshRenderer();

    void draw();

    void setPosition(glm::vec3 _pos);
    void setScale(glm::vec3 _scale);
    void setProgram(GLuint _pro);
    void setTexture(GLuint _textureId);
};


