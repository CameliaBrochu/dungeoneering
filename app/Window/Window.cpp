#include "Window.h"
#include <cmath>
#include "../Shader/Shader.h"
#include "../Shader/Program.h"

const char* vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
                                   "}\n\0";


Dungeoneering::Window::Window() {
    glfwInit();
    this->window = glfwCreateWindow(640, 480, "Hello world",NULL,NULL);
}

Dungeoneering::Window::~Window() {
    glfwTerminate();
}

void Dungeoneering::Window::Update() {
    glfwMakeContextCurrent(window);
    gladLoadGL();

    int width, height;
    glfwGetFramebufferSize(window,&width, &height);

    glViewport(0, 0, width, height);

    GLfloat vertices[] =
            {
                    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
                    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
                    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
            };


    Shader vertexShader(vertexShaderSource,shaderType::VERT);
    Shader fragmentShader(fragmentShaderSource,shaderType::FRAG);

    std::vector<Shader> shaders{vertexShader, fragmentShader};

    Program program(shaders);

    GLuint  VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);



    // Loop until window closed
    while(!glfwWindowShouldClose(window)){
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program.getProgram());
        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
