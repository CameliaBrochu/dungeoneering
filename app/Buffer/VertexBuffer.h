//
//

#ifndef DUNGEONEERING_VERTEXBUFFER_H
#define DUNGEONEERING_VERTEXBUFFER_H

#include <glad/glad.h>

namespace Dungeoneering{
    class VertexBuffer{
    public:
        GLuint VBO;

        VertexBuffer(GLfloat* verts, GLuint size){
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, size, verts, GL_STATIC_DRAW);
        }

        virtual ~VertexBuffer() {
            glDeleteBuffers(1, &VBO);
        }

        void bind() const{
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
        }

        void unbind() const{
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    };
}


#endif //DUNGEONEERING_VERTEXBUFFER_H
