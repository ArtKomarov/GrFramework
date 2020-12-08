#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ShaderProgram {
    GLuint program_;
    bool   isCompiled_;

    bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);

public:
    // Constructors
    ShaderProgram(ShaderProgram& sp) = delete;

    ShaderProgram(ShaderProgram&& sp) noexcept;

    ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);

    ShaderProgram(const char* vertexPath, const char* fragmentPath);

    //Destructor
    ~ShaderProgram();

    // Operators
    ShaderProgram& operator = (const ShaderProgram& sp) = delete;

    ShaderProgram& operator = (ShaderProgram &&sp) noexcept;

    bool isCompiled() const;

    GLuint getUniformLocation(const char* uniformName);

    void use() const;
};


#endif //SHADER_PROGRAM_HPP
