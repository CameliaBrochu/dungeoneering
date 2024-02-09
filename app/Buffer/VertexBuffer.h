#ifndef DUNGEONEERING_VERTEXBUFFER_H
#define DUNGEONEERING_VERTEXBUFFER_H

#include <glad/glad.h>
#include <vector>
#include "../Utils/Structs.cpp"


namespace Dungeoneering{
    class VertexBuffer{
    public:
        GLuint VBO;

        VertexBuffer(GLfloat* verts, GLuint size){
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, size, verts, GL_STATIC_DRAW);
        }

        VertexBuffer(const std::vector<Vec3<GLfloat>>& vertsVector){

            GLfloat verts[vertsVector.size() * 3];

            int count = 0;
            for (const Vec3<GLfloat>& vert: vertsVector) {
                verts[count] = vert.first;
                verts[count+1] = vert.second;
                verts[count+2] = vert.last;

                count = count+3;
            }

            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
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
