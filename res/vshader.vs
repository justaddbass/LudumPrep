#version 330

layout(location = 0) in vec4 vertex_position;
uniform mat4 VM;

void main() {
    gl_Position = VM * vertex_position;
}
