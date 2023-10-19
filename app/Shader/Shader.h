#ifndef DUNGEONEERING_SHADER_H
#define DUNGEONEERING_SHADER_H

#include <glad/glad.h>

namespace Dungeoneering {
    enum shaderType {
        VERT=GL_VERTEX_SHADER,
        FRAG=GL_FRAGMENT_SHADER
    };

    class Shader{
    public:
        Shader(const char* shaderSource, shaderType type){
            this->shader = glCreateShader(type);
            glShaderSource(this->shader, 1, &shaderSource, NULL);
            glCompileShader(this->shader);
        }

        virtual ~Shader(){
            glDeleteShader(this->shader);
        };

        GLuint getShader() const {
            return shader;
        }

    private:
        GLuint shader{};
    };
}

#endif //DUNGEONEERING_SHADER_H
