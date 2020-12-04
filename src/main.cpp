#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

#include "Renderer/shaderprogram.hpp"
#include "Renderer/vertexarray.hpp"
#include "Renderer/textureva.hpp"

#include "texture.hpp"
#include "mainwindow.hpp"

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


    std::cout << "Renderer: "       << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION)  << std::endl;
    //---------------------------------------------------------------------------//

    mainWindow.init();

    std::string vertexShaderCodeStr(vertexShaderCode);
    std::string fragmentShaderCodeStr(fragmentShaderCode);

    ShaderProgram shaderProgram(vertexShaderCodeStr, fragmentShaderCodeStr);

    if(!shaderProgram.isCompiled()) {
        std::cerr << "Can not create shader program!" << std::endl;
        return -1;
    }

    GLfloat trVertices[] = {
         0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    VertexArray vao(trVertices);

    //--------------------------------------Textures----------------------------------------//
//    // Load and create a texture
//    GLuint texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

//    // Set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//    // Load image, create texture and generate mipmaps
//    int width, height;
//    unsigned char* image = SOIL_load_image("../src/FinishScreen.jpg", &width, &height, 0, SOIL_LOAD_RGB);

//    if(!image)
//        return -1;

//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//    glGenerateMipmap(GL_TEXTURE_2D);

//    SOIL_free_image_data(image);

//    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.



    GLfloat texVertices[] = {
        // Positions          // Colors           // Texture Coords
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,  // Top Left
        0.5f,   0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
        0.5f,  -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f // Bottom Left
    };

//    GLuint texIndices[] = {
//        0, 1, 2, // First Triangle
//        0, 2, 3  // Second Triangle
//    };

//    ShaderProgram shProgForTexture("../src/Renderer/Shaders/texture_ex.vs", "../src/Renderer/Shaders/texture_ex.fs");
//    //ShaderProgram shProgForTexture(texVertexShaderCodeStr, texFragmentShaderCodeStr);

//    TextureVA textureVAO(texVertices, texIndices);

    Texture tex(texVertices, "../src/FinishScreen.jpg");


    /* Loop until the user closes the window */
    while (!mainWindow.shouldClose()) {
        mainWindow.clear();

        shaderProgram.use();

        //vao.bind();
        //vao.draw();

        tex.draw();

//        // Bind Texture
//        glBindTexture(GL_TEXTURE_2D, texture);

//        // Activate shader
//        shProgForTexture.use();

//        // Draw texture
//        textureVAO.draw();

        mainWindow.update();


        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
