#version 330

layout(location = 0) in vec3 vertex_position;
uniform mat4 V;
uniform mat4 M;

void main() {
    gl_Position = M * V * vec4(vertex_position, 1.0);
}
