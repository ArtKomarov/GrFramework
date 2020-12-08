#include <iostream>
#include <fstream>
#include <sstream>

#include "shaderprogram.hpp"

bool ShaderProgram::createShader(const std::string &source,
                                           const GLenum shaderType, GLuint &shaderID) {

    shaderID = glCreateShader(shaderType);

    const char* code = source.c_str();

    glShaderSource(shaderID, 1, &code, nullptr);
    glCompileShader(shaderID);

    GLint success;

    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

    if(!success) {
        GLchar infoLog[1024];
        glGetShaderInfoLog(shaderID, 1024, nullptr, infoLog);

        std::cerr << "Error: Shader: compile time error:\n" << infoLog << std::endl;
        return false;
    } else {
        return true;
    }
}

ShaderProgram::ShaderProgram(ShaderProgram &&sp) noexcept {
    program_ = sp.program_;
    isCompiled_ = sp.isCompiled_;

    sp.program_ = 0;
    sp.isCompiled_ = false;
}

ShaderProgram::ShaderProgram(const std::string &vertexShader,
                                       const std::string &fragmentShader) :
    program_(0),
    isCompiled_(false) {

    GLuint vertexShaderID;

    if(!this->createShader(vertexShader, GL_VERTEX_SHADER, vertexShaderID)) {
        std::cerr << "on VERTEX shader creation!" << std::endl;
        return;
    }

    GLuint fragmentShaderID;

    if(!this->createShader(fragmentShader, GL_FRAGMENT_SHADER, fragmentShaderID)) {
        std::cerr << "on FRAGMENT shader creation!" << std::endl;
        return;
    }

    program_ = glCreateProgram();

    glAttachShader(program_, vertexShaderID);
    glAttachShader(program_, fragmentShaderID);
    glLinkProgram(program_);

    GLint success;
    glGetProgramiv(program_, GL_LINK_STATUS, &success);

    if(!success) {
        GLchar infoLog[1024];
        glGetShaderInfoLog(program_, 1024, nullptr, infoLog);

        std::cerr << "Error: Shader: link time error:\n" << infoLog << std::endl;
        return;
    } else {
        isCompiled_ = true;
    }

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

ShaderProgram::ShaderProgram(const char *vertexPath, const char *fragmentPath) {

    // Get code from filePath
    std::string vertexCode;
    std::string fragmentCode;

    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // Make sure ifstream objects can throw exceptions
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);

        std::stringstream vShaderStream, fShaderStream;

        // Read data into sstreams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        // sstream -> GLchar*
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (const std::ifstream::failure& e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << std::endl;
    }

    new (this) ShaderProgram(vertexCode, fragmentCode);


    //------------------- TODO ----------------------

}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(program_);
}

ShaderProgram &ShaderProgram::operator = (ShaderProgram &&sp) noexcept {
    new (this) ShaderProgram(std::move(sp));
    return *this;
}

bool ShaderProgram::isCompiled() const {
    return isCompiled_;
}

GLuint ShaderProgram::getUniformLocation(const char *uniformName) {
    return glGetUniformLocation(program_, uniformName);
}

void ShaderProgram::use() const {
    glUseProgram(program_);
}
