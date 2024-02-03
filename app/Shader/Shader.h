#ifndef DUNGEONEERING_SHADER_H
#define DUNGEONEERING_SHADER_H

#include <glad/glad.h>
#include <fstream>
#include <format>

#include "../Utils/Debug.cpp"

namespace Dungeoneering {
    enum shaderType {
        VERT=GL_VERTEX_SHADER,
        FRAG=GL_FRAGMENT_SHADER
    };

    class Shader{
    public:
        Shader(const std::string& shaderSourcePath, shaderType type){
            this->shader = glCreateShader(type);
            std::string shaderFile = Shader::loadShaderFromFile(shaderSourcePath);
            const char* shaderSource = shaderFile.c_str();

            glShaderSource(this->shader, 1, &shaderSource, nullptr);
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

        static std::string loadShaderFromFile(const std::string& path){
            std::string content;

            std::ifstream fs("../app/Ressources/Shaders/" + path, std::ifstream::in);

            if(!fs.is_open()){
                throw std::runtime_error(std::format("Cannot read shader file \"{}\" ", path));
            }

            std::string line;
            while(!fs.eof()){
                std::getline(fs, line);
                content.append(line + "\n");
            }
            fs.close();

            return content;
        }
    };
}

#endif //DUNGEONEERING_SHADER_H
