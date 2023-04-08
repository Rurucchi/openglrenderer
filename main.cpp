#define GLFW_INCLUDE_NONE
#include <iostream>
#include <string.h>
#include <glad.h>
#include "./dependencies/glad.c"
#include <glfw3.h>


// functions definitions

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

void processInput(GLFWwindow *window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

// main stuff is here 

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  
  GLFWwindow* window = glfwCreateWindow(800, 600, "learn opengl", NULL, NULL);

  if (window == NULL)
  {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
  }    

glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

  glfwMakeContextCurrent(window);
  glViewport(0, 0, 800, 600);


while(!glfwWindowShouldClose(window))
{
    // user input
    processInput(window);

    // rendering stuff


    // buffers
    glfwSwapBuffers(window);
    glfwPollEvents();    
}

glfwTerminate();
    return 0;
}