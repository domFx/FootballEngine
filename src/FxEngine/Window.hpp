#pragma once

#include <string>

#include <glfw/glfw3.h>

namespace FxEngine {
	class Window {
        public:
            Window(const std::string&, unsigned int, unsigned int);
            ~Window();

            unsigned int Width() const;
            unsigned int Height() const;
            void Update();
            void Close();
        private:
            void Init();
        public:
            bool isRunning = false;
        private: 
            std::string title = "";
            unsigned int height = 0;
            unsigned int width = 0;
            GLFWwindow* window;
	};
}