#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer/shaderprogram.hpp"
#include "Renderer/vertexarray.hpp"
#include "Renderer/textureva.hpp"

#include "texture.hpp"
#include "mainwindow.hpp"
#include "button.hpp"

const char* vertexShaderCode =
                "#version 330 core\n"
                "layout (location = 0) in vec3 position;\n"
                "layout (location = 1) in vec3 color;\n"
                "out vec3 vertexColor;\n"
                "void main()\n"
                "{\n"
                "    gl_Position = vec4(position, 1.0);\n"
                "    vertexColor = color;\n"
                "}\n";

const char* fragmentShaderCode =
        "#version 330 core\n"
        "out vec4 fragColor;\n"
        "in vec3 vertexColor;\n"
        "void main()\n"
        "{\n"
        "    fragColor = vec4(vertexColor, 1.0f);\n"
        "}\n";

void checkOnclickFunc(GrFramework::ElemWidget* target) {
    if(target == nullptr)
        return;

    GLfloat transformColor[3] = {
        0.5, 0.5, 0.5
    };

    (*target).changeColor(static_cast<const void *>(transformColor));

}

int main(void) {
    //----------------------Initialize the library----------------------//
    if (!glfwInit()) {
        std::cerr << "Can't init GLFW!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //------------------------------------------------------------------//

    /* Create a windowed mode window and its OpenGL context */
    //MainWindow mainWindow(400, 400, "Main window", nullptr, nullptr);

    //GLFWwindow* window = glfwCreateWindow(400, 400, "Main window", nullptr, nullptr);
    if (!GrFramework::mainWindow.windowAvailable()) {
        std::cerr << "glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    GrFramework::mainWindow.makeContextCurrent();
    //glfwMakeContextCurrent(window);


    //---------------------------------Load GLAD---------------------------------//
    if(!gladLoadGL()) {
        std::cerr << "Can't load GLAD" << std::endl;
        return -1;
    }


    std::cout << "Renderer: "       << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION)  << std::endl;
    //---------------------------------------------------------------------------//

    glm::ivec2 g_WindowSize(640, 480);

    GrFramework::mainWindow.init();

    std::string vertexShaderCodeStr(vertexShaderCode);
    std::string fragmentShaderCodeStr(fragmentShaderCode);

    GrFramework::ShaderProgram shaderProgram(vertexShaderCodeStr, fragmentShaderCodeStr);

    if(!shaderProgram.isCompiled()) {
        std::cerr << "Can not create shader program!" << std::endl;
        return -1;
    }

    GLfloat trVertices[] = {
         0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    GrFramework::VertexArray vao(trVertices);

    //--------------------------------------Textures----------------------------------------//

    GLfloat texVertices[] = {
        // Positions          // Colors           // Texture Coords
        0.5f,   0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
        0.5f,  -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left
    };

    GrFramework::Texture tex(texVertices, "../src/BoxTexture.png");
    //--------------------------------------------------------------------------------------//

    //------------------------------------Button-------------------------------------//

    GLfloat butVertices[] = {
        // Positions         // Colors            // Texture Coords
        0.8f, 0.8f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, // Top Right
        0.8f, 0.6f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, // Bottom Right
        0.6f, 0.6f, 0.0f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f, // Bottom Left
        0.6f, 0.8f, 0.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f  // Top Left
    };

    GrFramework::ElemWidget* el = nullptr;

    GrFramework::Button but(butVertices, "../src/BoxTexture.png", el, checkOnclickFunc);

    (*GrFramework::mainWindow.manager_).regWidget(&but);

    //-------------------------------------------------------------------------------//


    /* Loop until the user closes the window */
    while (!GrFramework::mainWindow.shouldClose()) {
        GrFramework::mainWindow.clear();

        shaderProgram.use();

        vao.bind();
        vao.draw();

        glm::mat4 trans(1.0f);
        trans = glm::translate (trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate    (trans, (GLfloat)glfwGetTime() * 1.0f, glm::vec3(0.0f, 0.0f, 1.0f));

        tex.setTransformPos(trans);

        tex.draw();

        GrFramework::mainWindow.draw();

        GrFramework::mainWindow.update();


        /* Poll for and process events */
        glfwPollEvents();

        GrFramework::mainWindow.manager_->handleEvents();
    }

    glfwTerminate();
    return 0;
}
