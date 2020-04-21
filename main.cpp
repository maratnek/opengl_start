#include <iostream>
// glm
#include "glm/glm.hpp"
//#include <cstdlib>
// glew
#include "GL//glew.h"
// glfw
#include "GLFW/glfw3.h"

//#include "Mesh/Mesh.h"

void renderScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 1.0f, 0.0f, 0.5f);
  //glFlush();
  //glLoadIdentity();
  //std::cout << "Update Render" << std::endl;

  // Draw game object here
}

int main()
{
  std::cout << "Start glfw" << std::endl;
  std::cout << "Start glm" << std::endl;
  glm::vec4 position = glm::vec4(glm::vec3(0.0), 1.0);
  glm::mat4 model = glm::mat4(1.0);
  model[3] = glm::vec4(1.0, 1.0, 0.0, 1.0);
  glm::vec4 transformed = model * position;

  if (glfwInit())
  {
    std::cout << "GLFW Init" << std::endl;
    GLFWwindow* window = glfwCreateWindow(200, 100, "Winner", NULL, NULL);

    while (!glfwWindowShouldClose(window))                 // render our scene
    {
//      int width, height;
//      glfwGetFramebufferSize(window, &width, &height);
//      //ratio = width / (float)height;
//      glViewport(0, 0, width, height);
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

  system("pause");
}
