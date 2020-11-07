#include <iostream>

#include "mainwindow.hpp"

MainWindow mainWindow(500, 500, "Main window", nullptr, nullptr);

MainWindow::MainWindow(int width, int height,
                       const char* title,
                       GLFWmonitor* monitor,
                       GLFWwindow* share) :
    WindowManager(width, height) {


    //----------------------Initialize the library----------------------//
    if (!glfwInit()) {
        std::cerr << "Can't init GLFW!" << std::endl;
        return;
    }

    window_ = glfwCreateWindow(width, height, title, monitor, share);

    if(window_ == nullptr)
        return;
    glfwSetWindowSizeCallback(window_, glfwWindowSizeCallback);
}

void MainWindow::update() {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window_);
}

bool MainWindow::windowAvailable() const {
    if(window_)
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
    mainWindow.setWidth(width);
    std::cout << "RESIZE!!!!!" << std::endl;
    mainWindow.setHeigth(height);
    glViewport(0, 0, width, height);
}
