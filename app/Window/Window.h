#ifndef DUNGEONEERING_WINDOW_H
#define DUNGEONEERING_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Dungeoneering {

    struct Color {
        float r = 0.0;
        float g = 0.0;
        float b = 0.0;
        float a = 1.0f;
        Color(float r, float g,float b): r(r), g(g), b(b){};
        Color(float r, float g,float b, float a): r(r), g(g), b(b), a(a){};
    };

    class Window {
    public:
        Window();
        virtual ~Window();

        void Update();
    private:
        GLFWwindow* window{};

        void setBackgroundColor(Color rgba);
    };
}



#endif //DUNGEONEERING_WINDOW_H
