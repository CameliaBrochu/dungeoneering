#include "App.h"

namespace Dungeoneering {
    App::App() {

    }

    App::~App() = default;

    void App::Run() {
        this->mainWindow = std::make_unique<Window>();
        this->running = true;

        this->mainWindow->Update();
    }
} // Dungeoneering