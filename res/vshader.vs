#version 330

layout(location = 0) in vec3 vertex_position;
uniform mat4 VM;

void main() {
    gl_Position = VM * vec4(vertex_position, 1.0);
}
