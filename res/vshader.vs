#version 330

layout(location = 0) in vec4 vertex_position;
layout(location = 1) in vec3 vertexColor;
out vec3 fragmentColor;
uniform mat4 VM;

void main() {
    gl_Position = VM * vertex_position;
    fragmentColor = vertexColor;
}
