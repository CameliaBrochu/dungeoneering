#include "Window.h"
#include <cmath>

#include "../Shader/Shader.h"
#include "../Shader/Program.h"
#include "../Buffer/VertexBuffer.h"
#include "../Buffer/VertexArray.h"

GLfloat vertices[] =
        {
                -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
                0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
                0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
        };

Dungeoneering::Window::Window() {
    glfwInit();
    this->window = glfwCreateWindow(640, 480, "Hello world",NULL,NULL);
    glfwMakeContextCurrent(this->window);
}

Dungeoneering::Window::~Window() {
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

void Dungeoneering::Window::Update() {
    gladLoadGL();
    int width, height;
    glfwGetFramebufferSize(window,&width, &height);

    glViewport(0, 0, width, height);


    Shader vertexShader("default.vert",shaderType::VERT);
    Shader fragmentShader("default.frag",shaderType::FRAG);

    std::vector<Shader*> shaders = {&vertexShader, &fragmentShader};

    Program program;
    program.attachShaders(shaders);

    VertexArray VAO;
    VAO.bind();

    VertexBuffer VBO(vertices, sizeof(vertices));
    VBO.bind();
    VAO.linkVBO(VBO, 0);

    VAO.unbind();
    VBO.unbind();
    // Loop until window closed
    while(!glfwWindowShouldClose(window)){
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program.getProgram());
        VAO.bind();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
