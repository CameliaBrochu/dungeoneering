#include <vector>
#include "glad/glad.h"
#include "Grid.h"
#include "../Buffer/VertexArray.h"
#include "../Buffer/ElementBuffer.h"

namespace Dungeoneering {
    void Grid::render() {
        int slices = 10;

        std::vector<Vec3<GLfloat>> vertices;

        for (int i = 0; i < slices; ++i) {
            GLfloat x = (float)i / (float)slices;
            vertices.push_back(Vec3<GLfloat>(x * 2.0f - 1.0f, -(float)this->height/2, 0));
            vertices.push_back(Vec3<GLfloat>(x * 2.0f - 1.0f, (float)this->height/2, 0));
        }

        for (int i = 0; i < slices; ++i) {
            GLfloat y = (float)i / (float)slices;
            vertices.push_back(Vec3<GLfloat>(-(float)this->width/2, y * 2.0f - 1.0f, 0));
            vertices.push_back(Vec3<GLfloat>((float)this->width/2, y * 2.0f - 1.0f, 0));
        }

        std::vector<GLuint> ind;
        for (int i = 0; i < vertices.size(); ++i) {
            ind.push_back(i);
        }

        VertexArray VAO;
        VAO.bind();

        VertexBuffer VBO(vertices);
        VBO.bind();
        ElementBuffer EBO(ind);
        EBO.bind();

        VAO.linkVBO(VBO, 0);


        glDrawElements(GL_LINES, (int)vertices.size() * 3, GL_UNSIGNED_INT, nullptr);

        VBO.unbind();
        EBO.unbind();
        VAO.unbind();
    }
}
