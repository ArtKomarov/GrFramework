#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>


#include "Renderer/shaderprogram.hpp"
#include "Renderer/textureva.hpp"

namespace GrFramework {

enum class transformObj {
    COLOR,
    POS,
    TEX_COORDS,
};

class Texture {
    GLuint texture_;
    int    width_;
    int    height_;

    ShaderProgram shProgram_;
    TextureVA     vao_;

    glm::vec3 transformColor_;

    glm::mat4 transformPos_;

    glm::mat2 transformTexCoords_;
    //std::string vsPath;
    //std::string fsPath;

    void transformColor();

    void transformTexCoords();

    void transformPos();
public:

    Texture(const GLfloat *vertices, const char *texPath);

    void setTransformColor(const glm::vec3 &vec);

    void setTransformTexCoords(const glm::mat2 &matrix);

    void setTransformPos(const glm::mat4& matrix);

    void draw();
};

}

#endif // TEXTURE_HPP
