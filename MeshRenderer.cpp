#include "MeshRenderer.h"

MeshRenderer::MeshRenderer(MeshType modelType, Camera *_camera, btRigidBody* _rigid)
: camera(_camera),
    rigidBody(_rigid)
{
    // camera = _camera;
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
    position = glm::vec3(0.0, 0.0, 0.0);

    switch (modelType) {
        case MeshType::kTriangle: Mesh::setTriData(vertices, indices);
        break;
        case MeshType::kQuad: Mesh::setQuadData(vertices, indices);
        break;
        case MeshType::kSphere: Mesh::setSphereData(vertices, indices);
        break;
        case MeshType::kCube: Mesh::setCubeData(vertices, indices);
        break;
    };

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(),&vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indices.size(), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) (offsetof(Vertex,Vertex::texCoords)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::draw() 
{
    btTransform t;
    rigidBody->getMotionState()->getWorldTransform(t);
    btQuaternion r = t.getRotation();
    btVector3 translate = t.getOrigin();
    glm::mat4 RotationMatrix = glm::rotate(glm::mat4(1.0f), r.getAngle(), glm::vec3(r.getAxis().getX(), r.getAxis().getY(), r.getAxis().getZ()));
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(translate.getX(), translate.getY(), translate.getZ()));
    glm::mat4 ScaleMatrix = glm::scale(glm::mat4(1.0f), scale);

    glm::mat4 TranslationMatrixPos = glm::translate(glm::mat4(1.0f), position);
    // glm::mat4 ScaleMatrix = glm::scale(glm::mat4(1.0f), scale);
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = TranslationMatrix * ScaleMatrix * RotationMatrix * TranslationMatrixPos;

    glm::mat4 vp = camera->getProjectionMatrix() * camera->getViewMatrix();
    glUseProgram(this->program);
    GLint vpLoc = glGetUniformLocation(program, "vp");
    glUniformMatrix4fv(vpLoc, 1, GL_FALSE, glm::value_ptr(vp));

    GLint modelLoc = glGetUniformLocation(program, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glBindTexture(GL_TEXTURE_2D, texture);
    
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

// Setter functions

void MeshRenderer::setPosition(glm::vec3 _pos) 
{
    position = _pos;
}

void MeshRenderer::setScale(glm::vec3 _scale) 
{
    scale = _scale;
}

void MeshRenderer::setProgram(GLuint _pro) 
{
    program = _pro;
}

void MeshRenderer::setTexture(GLuint _textureId) 
{
    texture = _textureId;
}