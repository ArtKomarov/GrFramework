#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "mainwindow.hpp"

int main(void) {

    //----------------------Initialize the library----------------------//
    if (!glfwInit()) {
        std::cerr << "Can't init GLFW!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //------------------------------------------------------------------//

    /* Create a windowed mode window and its OpenGL context */
    //MainWindow mainWindow(400, 400, "Main window", nullptr, nullptr);

    //GLFWwindow* window = glfwCreateWindow(400, 400, "Main window", nullptr, nullptr);
    if (!mainWindow.windowAvailable()) {
        std::cerr << "glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    mainWindow.makeContextCurrent();
    //glfwMakeContextCurrent(window);


    //---------------------------------Load GLAD---------------------------------//
    if(!gladLoadGL()) {
        std::cerr << "Can't load GLAD" << std::endl;
        return -1;
    }

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version" << glGetString(GL_VERSION) << std::endl;
    //---------------------------------------------------------------------------//

    glClearColor(1, 0, 0, 1);

    /* Loop until the user closes the window */
    while (!mainWindow.shouldClose()) {
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        //glfwSwapBuffers(window);

        mainWindow.update();

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
