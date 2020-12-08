#include <iostream>

#include <SOIL/SOIL.h>
#include <glm/gtc/type_ptr.hpp>

#include "texture.hpp"

GLuint defTextureIndices_[] = {
    0, 1, 3, // First Triangle
    1, 2, 3  // Second Triangle
};

Texture::Texture(const GLfloat *vertices, const char* texPath) :
    shProgram_("../src/Renderer/Shaders/texture_ex.vs", "../src/Renderer/Shaders/texture_ex.fs"),
    vao_(vertices, defTextureIndices_),
    transformColor_(1.0f),
    transformPos_(1.0f),
    transformTexCoords_(1.0f) {

    //GLuint transformLoc = glGetUniformLocation(shProgram_., "transform");
    //glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    // Load and create a texture
    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load image, create texture and generate mipmaps
    int width, height;
    unsigned char* image = SOIL_load_image(texPath, &width, &height, 0, SOIL_LOAD_RGB);

    if(!image)
        return;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);

    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}

void Texture::transformColor() {
    GLuint transformLoc = shProgram_.getUniformLocation("transformColor");

    //std::cout << __PRETTY_FUNCTION__ << ": " << transformLoc << std::endl;

    glUniform3fv(transformLoc, 1, glm::value_ptr(transformColor_));
}

void Texture::transformTexCoords() {
    GLuint transformLoc = shProgram_.getUniformLocation("transformTexCoords");

    //std::cout << __PRETTY_FUNCTION__ << ": " << transformLoc << std::endl;

    glUniformMatrix2fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformTexCoords_));
}

void Texture::transformPos() {
    GLuint transformLoc = shProgram_.getUniformLocation("transformPos");

    //std::cout << __PRETTY_FUNCTION__ << ": " << transformLoc << std::endl;

    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformPos_));
}

void Texture::setTransformColor(const glm::vec3 &vec) {
    transformColor_ = vec;
}

void Texture::setTransformTexCoords(const glm::mat2 &matrix) {
    transformTexCoords_ = matrix;
}

void Texture::setTransformPos(const glm::mat4 &matrix) {
    transformPos_ = matrix;
}



void Texture::draw() {
    glBindTexture(GL_TEXTURE_2D, texture_);

    shProgram_.use();

    this->transformColor();
    this->transformPos();
    this->transformTexCoords();

    vao_.draw();
}
