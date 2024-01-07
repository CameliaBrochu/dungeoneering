#ifndef DUNGEONEERING_UTILS_DEBUG
#define DUNGEONEERING_UTILS_DEBUG

#include <string>
#include <sstream>
#include <iostream>
#include "glad/glad.h"

namespace Utils{
    inline std::string glCheckError()
    {
        // Get the last error
        GLenum lastError = glGetError();
        std::stringstream  err;

        err << "";

        if (lastError != GL_NO_ERROR) {
            std::string error = "UNDEFINED";

            switch (lastError)
            {
                case GL_INVALID_ENUM:
                    error = "GL_INVALID_ENUM";
                    break;

                case GL_INVALID_VALUE:
                    error = "GL_INVALID_VALUE";
                    break;

                case GL_INVALID_OPERATION:
                    error = "GL_INVALID_OPERATION";
                    break;

                case GL_STACK_OVERFLOW:
                    error = "GL_STACK_OVERFLOW";
                    break;

                case GL_STACK_UNDERFLOW:
                    error = "GL_STACK_UNDERFLOW";
                    break;

                case GL_OUT_OF_MEMORY:
                    error = "GL_OUT_OF_MEMORY";
                    break;

                case GL_INVALID_FRAMEBUFFER_OPERATION:
                    error = "GL_INVALID_FRAMEBUFFER_OPERATION";
                    break;
            }

            err << error ;
        }
        return err.str();
    }
}

#endif //DUNGEONEERING_UTILS_DEBUG

