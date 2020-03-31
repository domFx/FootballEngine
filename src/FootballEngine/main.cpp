#include "Window.h" 

using namespace FootballEngine;
 
int main(void) {
    Window* w = nullptr;
    w = new Window("Football Engine", 1270, 720);

    while(w->isRunning) {
        w->Update();
    }

    delete w;
    
    return 0;
}
 