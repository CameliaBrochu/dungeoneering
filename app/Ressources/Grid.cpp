//
//

#include <vector>
#include <iostream>
#include "glad/glad.h"
#include "Grid.h"
#include "../Buffer/VertexArray.h"
#include "../Buffer/ElementBuffer.h"

void Dungeoneering::Grid::render() {
    int slices = 10;

    std::vector<Vec3<GLfloat>> vertices;

    for (int j = 0; j <= slices; ++j) {
        for (int i = 0; i <= slices; ++i) {
            GLfloat x = (float)i / (float)slices;
            GLfloat y = (float)j / (float)slices;
            GLfloat z = 0;
            vertices.push_back(Vec3<GLfloat>(x * 2.0f - 1.0f, y * 2.0f - 1.0f, z));
        }
    }

    std::vector<GLuint> ind;

    for (int j = 0; j < slices; ++j) {
        for (int i = 0; i < slices; ++i) {
            GLuint row1 = j * (slices + 1);
            GLuint row2 = (j + 1) * (slices + 1);

            ind.push_back(row1 + i);
            ind.push_back(row1 + i + 1);
            ind.push_back(row2 + i);
            ind.push_back(row1 + i);
            ind.push_back(row2 + i + 1);
            ind.push_back(row2 + i);
        }
    }

    VertexArray VAO;
    VAO.bind();

    VertexBuffer VBO(vertices);
    VBO.bind();
    ElementBuffer EBO(ind);
    EBO.bind();

    VAO.linkVBO(VBO, 0);


    glDrawElements(GL_LINES, ind.size() * 3, GL_UNSIGNED_INT, NULL);

    VBO.unbind();
    EBO.unbind();
    VAO.unbind();
}
