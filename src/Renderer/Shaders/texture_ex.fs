#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;

uniform mat2 transformTexCoords;
uniform vec3 transformColor;

void main() {
    color = texture(ourTexture, transformTexCoords * TexCoord) * vec4(transformColor * ourColor, 1.0f);
}
