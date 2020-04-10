#include <memory>

#include "Window.hpp" 

using namespace FxEngine;
 
int main(void) {
    std::unique_ptr<Window> w = std::make_unique<Window>("Fx Engine", 1270, 720);

    while(w->isRunning) {
        w->Update();
    }
    
    return 0;
}