#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "windowmanager.hpp"

class MainWindow final : public WindowManager {
    GLFWwindow* window_;

public:
    MainWindow(int          width,
               int          height,
               const char*  title,
               GLFWmonitor* monitor,
               GLFWwindow*  share);

    // Init after load glad
    void init();

    // Clear and draw background
    void update() override;

    void clear();

    // Check, if window != nullptr
    bool windowAvailable() const;

    bool checkWindow(const GLFWwindow *window) const;

    // Should window close now?
    int shouldClose() const;

    // Make main window as the current context
    void makeContextCurrent();
};

void glfwWindowSizeCallback(GLFWwindow *window, int width, int height);

extern MainWindow mainWindow;

#endif // MAINWINDOW_HPP
