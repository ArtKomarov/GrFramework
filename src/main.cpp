#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer/shaderprogram.hpp"

#include "mainwindow.hpp"


// Triangle

GLfloat trPoint[] = {
     0.0f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};

GLfloat trColor[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

const char* vertexShader =
        "#version 330 core\n"
        "layout(location = 0) in vec3 vertex_position;"
        "layout(location = 1) out vec3 vertex_color;"
        "out vec3 color;"
        "void main() {"
        "    gl_Position = vec4(vertex_position, 1.0);"
        "    color = vertex_color;"
        "}";

const char* fragmentShader =
        "#version 330 core\n"
        "out vec4 frag_color;"
        "in vec3 color;"
        "void main() {"
        "    frag_color = vec4(color, 1.0);"
        "}";

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
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "|||" << GL_VERSION_4_6 << std::endl;
    //---------------------------------------------------------------------------//

    glClearColor(1, 1, 1, 1); // initAfterGL_Loaded

    // Triangle
//    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vs, 1, &vertexShader, nullptr);
//    glCompileShader(vs);

//    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fs, 1, &fragmentShader, nullptr);
//    glCompileShader(fs);

//    GLuint shader_program = glCreateProgram();
//    glAttachShader(shader_program, vs);
//    glAttachShader(shader_program, fs);
//    glLinkProgram(shader_program);


//    glDeleteShader(vs);
//    glDeleteShader(fs);

    std::string vertexShaderStr(vertexShader);
    std::string fragmentShaderStr(fragmentShader);

    Renderer::ShaderProgram shaderProgram(vertexShaderStr, fragmentShaderStr);

    if(!shaderProgram.isCompiled()) {
        std::cerr << "Can not create shader program!" << std::endl;
        return -1;
    }

    GLuint points_vbo = 0;
    glGenBuffers(1, &points_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(trPoint), trPoint, GL_STATIC_DRAW);

    GLuint colors_vbo = 0;
    glGenBuffers(1, &colors_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(trColor), trColor, GL_STATIC_DRAW);

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);


    // Rect
    /*
    GLuint tex;
    glGenTextures(1, &tex);

    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Border color
    float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Black/white checkerboard
    float pixels[] = {
        0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
    };
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
    */


    /* Loop until the user closes the window */
    while (!mainWindow.shouldClose()) {
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        //glfwSwapBuffers(window);

        mainWindow.clear();

        shaderProgram.use();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        mainWindow.update();


        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
