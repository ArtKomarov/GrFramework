#ifndef VERTEXARRAY_HPP
#define VERTEXARRAY_HPP

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace GrFramework {

class VertexArray {
    GLuint vao_;

    void setupBuffer(int );
public:
    VertexArray() = delete;

    VertexArray(VertexArray& va) = delete;

    VertexArray(VertexArray&& va);

    VertexArray(GLfloat* vertices);

    // Operators
    VertexArray& operator = (VertexArray& va) = delete;

    VertexArray& operator = (VertexArray&& va);

    void bind();

    void draw();

};

}

#endif // VERTEXARRAY_HPP
