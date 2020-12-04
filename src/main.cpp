#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

#include "Renderer/shaderprogram.hpp"
#include "Renderer/vertexarray.hpp"
#include "Renderer/textureva.hpp"

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

const char* texVertexShaderCode =
        "#version 330 core\n"
        "layout (location = 0) in vec3 position;"
        "layout (location = 1) in vec3 color;"
        "layout (location = 2) in vec2 texCoord;"
        "out vec3 outColor;"
        "out vec2 TexCoord;"
        "void main() {"
        "TexCoord = texCoord;"
        "gl_Position = vec4(position, 1.0f);"
        "outColor = color;"
        "}";

const char* texFragmentShaderCode =
        "#version 330 core\n"
        "in vec3 ourColor;\n"
        "in vec2 TexCoord;\n"
        "out vec4 color;\n"
        "uniform sampler2D ourTexture;\n"
        "void main()\n"
        "{\n"
        "    color = texture(ourTexture, TexCoord);\n"
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
    // Load and create a texture
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load image, create texture and generate mipmaps
    int width, height;
    unsigned char* image = SOIL_load_image("../src/FinishScreen.jpg", &width, &height, 0, SOIL_LOAD_RGB);

    if(!image)
        return -1;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);

    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.



    GLfloat texVertices[] = {
        // Positions          // Colors           // Texture Coords
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,  // Top Left
        0.5f,   0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
        0.5f,  -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f // Bottom Left
    };

    GLuint texIndices[] = {
        0, 1, 2, // First Triangle
        0, 2, 3  // Second Triangle
    };

    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    std::string texVertexShaderCodeStr(texVertexShaderCode);
    std::string texFragmentShaderCodeStr(texFragmentShaderCode);

    ShaderProgram shProgForTexture("../src/Renderer/Shaders/texture_ex.vs", "../src/Renderer/Shaders/texture_ex.fs");
    //ShaderProgram shProgForTexture(texVertexShaderCodeStr, texFragmentShaderCodeStr);

    TextureVA textureVAO(texVertices, texIndices);

//    GLuint VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);

//    glBindVertexArray(VAO);

//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(texVertices), texVertices, GL_STATIC_DRAW);

//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(texIndices), texIndices, GL_STATIC_DRAW);

//    // Position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Color attribute
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//    glEnableVertexAttribArray(1);
//    // TexCoord attribute
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//    glEnableVertexAttribArray(2);

//    glBindVertexArray(0); // Unbind VAO




    /* Loop until the user closes the window */
    while (!mainWindow.shouldClose()) {
        mainWindow.clear();

        shaderProgram.use();

        //vao.bind();
        //vao.draw();

        // Bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // Activate shader
        shProgForTexture.use();

        // Draw texture
        textureVAO.draw();
//        glBindVertexArray(VAO);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        glBindVertexArray(0);

        mainWindow.update();


        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
