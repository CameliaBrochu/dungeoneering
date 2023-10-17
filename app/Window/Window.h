#ifndef DUNGEONEERING_WINDOW_H
#define DUNGEONEERING_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Dungeoneering {
    class Window {
    public:
        Window();
        virtual ~Window();

        void Update();
    private:
        GLFWwindow* window{};
    };
}



#endif //DUNGEONEERING_WINDOW_H
