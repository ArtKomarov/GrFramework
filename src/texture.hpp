#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Renderer/shaderprogram.hpp"
#include "Renderer/textureva.hpp"

class Texture {
    GLuint texture_;
    int    width_;
    int    height_;

    ShaderProgram shProgram_;
    TextureVA     vao_;

    //std::string vsPath;
    //std::string fsPath;

public:
    Texture(GLfloat* vertices, const char *texPath);

    void draw();
};

#endif // TEXTURE_HPP
