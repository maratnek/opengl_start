#include <iostream>
// glm
#include "glm/glm.hpp"
//#include <cstdlib>
// glew
// #include "GL//glew.h"
#include <GL/glew.h>
// glfw
#include <GLFW/glfw3.h>

#include "Mesh/Mesh.h"
#include "Camera.h"
#include "ShaderLoader.h"
#include "LightRenderer.h"

Camera* camera;
LightRenderer* light;

void initGame() {
  glEnable(GL_DEPTH_TEST);

  ShaderLoader shader;

  GLuint flatShaderProgram = shader.createProgramm("Assets/Shaders/FlatModel.vs", "Assets/Shaders/FlatModel.fs");
  camera = new Camera(45.0f, 800, 600, 0.1f, 100.0f, glm::vec3(0.0f, 4.0f, 6.0f));

  light = new LightRenderer(MeshType::kTriangle, camera);
  light->setProgram(flatShaderProgram);
  light->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
}

void renderScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
  // glFlush();
  // glLoadIdentity();
  light->draw();
  std::cout << "Update Render" << std::endl;

  // Draw game object here
}

int main()
{
  std::cout << "Start glfw" << std::endl;
  std::cout << "Start glm" << std::endl;
  // glm::vec4 position = glm::vec4(glm::vec3(0.0), 1.0);
  // glm::mat4 model = glm::mat4(1.0);
  // model[3] = glm::vec4(1.0, 1.0, 0.0, 1.0);
  // glm::vec4 transformed = model * position;

  if (glfwInit())
  {
    std::cout << "GLFW Init" << std::endl;
    GLFWwindow *window = glfwCreateWindow(600, 800, "Winner", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();
    initGame();

    while (!glfwWindowShouldClose(window)) // render our scene
    {
      int width, height;
      glfwGetFramebufferSize(window, &width, &height);
      //ratio = width / (float)height;
      glViewport(0, 0, width, height);

      renderScene();
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwTerminate();
  }
  else
  {
    std::cerr << "Error GLFW Init" << std::endl;
  }
  
  delete camera;
  delete light;

  return 0;

}
