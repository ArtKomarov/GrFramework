#include <iostream>

#include "mainwindow.hpp"

MainWindow mainWindow(500, 500, "Main window", nullptr, nullptr);

MainWindow::MainWindow(int          width,
                       int          height,
                       const char*  title,
                       GLFWmonitor* monitor,
                       GLFWwindow*  share) :
    WindowManager() {


    // Initialize the library
    if (!glfwInit()) {
        std::cerr << "Can't init GLFW!" << std::endl;
        return;
    }

    window_ = glfwCreateWindow(width, height, title, monitor, share);

    if(window_ == nullptr)
        return;

    glfwSetWindowSizeCallback(window_, glfwWindowSizeCallback);
}

void MainWindow::init() {
    glClearColor(1, 1, 0, 1);
}

void MainWindow::update() {

    /* Swap front and back buffers */
    glfwSwapBuffers(window_);
}

void MainWindow::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

bool MainWindow::windowAvailable() const {
    if(window_)
        return true;
    else
        return false;
}

bool MainWindow::checkWindow(const GLFWwindow* window) const {
    if(window == window_)
        return true;
    else
        return false;
}

int MainWindow::shouldClose() const {
    return glfwWindowShouldClose(window_);
}

void MainWindow::makeContextCurrent() {
    glfwMakeContextCurrent(window_);
}

void glfwWindowSizeCallback(GLFWwindow* window, int width, int height) {
    glfwMakeContextCurrent(window);

    if(mainWindow.checkWindow(window)) {
        mainWindow.setWidth(width);
        mainWindow.setHeigth(height);

        std::cout << __PRETTY_FUNCTION__ << std::endl;
        glViewport(0, 0, width, height);
    }
}
