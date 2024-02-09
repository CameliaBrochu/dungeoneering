#ifndef DUNGEONEERING_VERTEXARRAY_H
#define DUNGEONEERING_VERTEXARRAY_H

#include "glad/glad.h"
#include "VertexBuffer.h"

namespace Dungeoneering {
    class VertexArray {
    public:
        GLuint VAO;

        VertexArray() {
            glGenVertexArrays(1, &VAO);
        }

        virtual ~VertexArray() {
            glDeleteVertexArrays(1, &VAO);
        }

        void linkVBO(VertexBuffer& VBO ,GLuint layout) const {
            VBO.bind();
            glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(layout);
            VBO.unbind();
        }

        void bind() const{
            glBindVertexArray(VAO);
        }

        void unbind() const{
            glBindVertexArray(0);
        }
    };
}

#endif //DUNGEONEERING_VERTEXARRAY_H
