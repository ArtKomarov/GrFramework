#include "vertexarray.hpp"

const int verArrayLength = 18;

VertexArray::VertexArray(VertexArray &&va) {
    vao_    = va.vao_;
    va.vao_ = 0;
}

VertexArray::VertexArray(GLfloat *vertices) {
    // Generate vertex array
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    // Vertex buffer object
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * verArrayLength, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

VertexArray &VertexArray::operator = (VertexArray &&va) {
    new (this) VertexArray(std::move(va));
    return *this;
}

void VertexArray::bind() {
    glBindVertexArray(vao_);
}

void VertexArray::draw() {
    glBindVertexArray(vao_);

    // Draw primitive, start id, number of vertexes
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);
}
