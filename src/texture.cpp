#include <SOIL/SOIL.h>

#include "texture.hpp"

GLuint defTextureIndices_[] = {
    0, 1, 2, // First Triangle
    0, 2, 3  // Second Triangle
};

Texture::Texture(GLfloat *vertices, const char* texPath) :
    shProgram_("../src/Renderer/Shaders/texture_ex.vs", "../src/Renderer/Shaders/texture_ex.fs"),
    vao_(vertices, defTextureIndices_) {

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

void Texture::draw() {
    glBindTexture(GL_TEXTURE_2D, texture_);

    shProgram_.use();

    vao_.draw();
}
