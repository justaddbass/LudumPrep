#version 330

in vec2 UV;
out vec3 color;

uniform sampler2D texSampler;

void main() {
    color = vec3(texture(texSampler, UV));
}
