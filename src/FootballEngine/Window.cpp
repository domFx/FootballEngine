#include "Window.h"

namespace FootballEngine {

    Window::Window(
        const std::string& title,
        unsigned int width,
        unsigned int height
    ) : title(title), width(width), height(height) { 
        Init();
    }

    Window::~Window() { }

    void Window::Init() {
        if (!glfwInit()) {
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        glfwSetErrorCallback([](int error, const char* description) {
            fprintf(stderr, "Error: %s\n", description);
        });

        window = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);

        if (!window) {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        isRunning = true;

        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
        });

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
    
    }

    void Window::Update() {
        if(glfwWindowShouldClose(window)) {
            Close();
            return;
        }

        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } 

    void Window::Close() {
        isRunning = false;
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    unsigned int Window::Height() const { return height; }

    unsigned int Window::Width() const { return width; }
}