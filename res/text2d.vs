#version 330

layout(location = 0) in vec2 vertex_pos_screenspace;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;

void main() {
    vec2 vertex_pos = vertex_pos_screenspace - vec2(125.5,125.5);
    vertex_pos /= vec2(125.5,125.5);
    gl_Position = vec4(vertex_pos, 0, 1);

    UV = vertexUV;
}
