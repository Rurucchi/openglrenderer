#define GLFW_INCLUDE_NONE
#include <iostream>
#include <string.h>
#include <glad.h>
#include "./dependencies/glad.c"
#include <glfw3.h>


// ------------------- functions definitions

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

void processInput(GLFWwindow *window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

// ----------------- variables

// floats 
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
}; 

// shaders
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

// unsigned
unsigned int VBO;

unsigned int vertexShader;
vertexShader = glCreateShader(GL_VERTEX_SHADER);

// ----------------- rendering process

int main()
{

    //initialize GL
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  
  // initial window size
  GLFWwindow* window = glfwCreateWindow(800, 600, "learn opengl", NULL, NULL);

  //error handling
  if (window == NULL)
  {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
  }

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
  }    

  // window resize handling
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  glfwMakeContextCurrent(window);
  glViewport(0, 0, 800, 600);


// ----------------------- actually drawing stuff

  // window closing handling
  while(!glfwWindowShouldClose(window))
  {

      // user input
      processInput(window);

      // rendering stuff
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      glGenBuffers(1, &VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, VBO); 
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

          // buffers
      glfwSwapBuffers(window);
      glfwPollEvents();    
  }

  glfwTerminate();
    return 0;
}