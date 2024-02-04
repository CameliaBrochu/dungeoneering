//
//

#ifndef DUNGEONEERING_ELEMENTBUFFER_H
#define DUNGEONEERING_ELEMENTBUFFER_H

#include <glad/glad.h>
#include <vector>
#include "../Utils/Structs.cpp"

namespace Dungeoneering{
    class ElementBuffer{
    public:
        GLuint EBO;

        ElementBuffer(GLuint * indices, GLuint size){
            glGenBuffers(1, &EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
        }

        ElementBuffer(const std::vector<GLuint>& indicesVector){

            GLuint indices[indicesVector.size()];

            int count = 0;
            for (const GLuint& i: indicesVector) {
                indices[count] = i;

                ++count;
            }

            glGenBuffers(1, &EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        }

        virtual ~ElementBuffer() {
            glDeleteBuffers(1, &EBO);
        }

        void bind() const{
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        }

        void unbind() const{
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
    };
}

#endif //DUNGEONEERING_ELEMENTBUFFER_H
