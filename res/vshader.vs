#version 330

layout(location = 0) in vec3 vertex_position;

void main() {
    gl_position = vertex_position;
}
