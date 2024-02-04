#include "Window.h"
#include <cmath>

#include "../Shader/Shader.h"
#include "../Shader/Program.h"

#include "../Ressources/Grid.h"

Dungeoneering::Window::Window() {
    glfwInit();
    this->window = glfwCreateWindow(800, 800, "Hello world",NULL,NULL);
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

    Grid grid;

    // Loop until window closed
    while(!glfwWindowShouldClose(window)){
        this->setBackgroundColor(Color(1.0f, 0.88f, 0.73f));

        glUseProgram(program.getProgram());

        grid.render();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Dungeoneering::Window::setBackgroundColor(Color rgba) {
    glClearColor(rgba.r, rgba.g, rgba.b, rgba.a);
    glClear(GL_COLOR_BUFFER_BIT);
}
