#include "Window.h"
#include <cmath>

#include "../Shader/Shader.h"
#include "../Shader/Program.h"

#include "../Ressources/Grid.h"
#include "../Ressources/Shape/Shape.h"
#include "../Ressources/Shape/Line.h"

namespace Dungeoneering {
    Window::Window() {
        glfwInit();
        this->window = glfwCreateWindow(800, 800, "Hello world",NULL,NULL);
        glfwMakeContextCurrent(this->window);
    }

    Window::~Window() {
        glfwDestroyWindow(this->window);
        glfwTerminate();
    }

    void Window::Update() {
        gladLoadGL();
        int width, height;
        glfwGetFramebufferSize(window,&width, &height);

        glViewport(0, 0, width, height);


        Shader vertexShader("default.vert",shaderType::VERT);
        Shader fragmentShader("default.frag",shaderType::FRAG);

        std::vector<Shader*> shaders = {&vertexShader, &fragmentShader};

        Program program;
        program.attachShaders(shaders);

        Grid grid(width, height);
        glUseProgram(program.getProgram());

        Shape testShape;
        testShape.addSegment(new Line(Coords2D(10,10), Coords2D(10,100)));
        testShape.addSegment(new Line(Coords2D(10,100), Coords2D(100,100)));
        testShape.addSegment(new Line(Coords2D(100,100), Coords2D(200,200)));

        // Loop until window closed
        while(!glfwWindowShouldClose(window)){
            this->setBackgroundColor(Color(1.0f, 0.88f, 0.73f));

            grid.render();
            testShape.render();


            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    void Window::setBackgroundColor(Color rgba) {
        glClearColor(rgba.r, rgba.g, rgba.b, rgba.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}
