#ifndef DUNGEONEERING_APP_H
#define DUNGEONEERING_APP_H

#include <memory>
#include "Window/Window.h"

namespace Dungeoneering {

    class App {
    public:
        App();
        virtual ~App();

        void Run();

    private:
        std::unique_ptr<Window> mainWindow;
        bool running = false;
    };

} // Dungeoneering

#endif //DUNGEONEERING_APP_H
