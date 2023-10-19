#ifndef DUNGEONEERING_PROGRAM_H
#define DUNGEONEERING_PROGRAM_H

#include <glad/glad.h>
#include <vector>
#include "Shader.h"

namespace Dungeoneering {
    class Program{
    public:
        Program(const std::vector<Shader> &shaders) {
            this->program = glCreateProgram();

            for (const auto& s: shaders) {
                glAttachShader(this->program,s.getShader());
            }

            glLinkProgram(this->program);
        }

        virtual ~Program() {
            glDeleteProgram(this->program);
        }

        GLuint getProgram() const {
            return program;
        }

    private:
        GLuint program{};
    };
}

#endif //DUNGEONEERING_PROGRAM_H
