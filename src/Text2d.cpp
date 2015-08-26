#include "Text2d.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Text2d::Text2d(float x, float y, int size) {
    _x = x;
    _y = y;
    _size = size;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &uv_buffer);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    int width, height, numComponents;
	unsigned char* imageData = stbi_load("res/text-atlas.png", &width, &height, &numComponents, 4);

	if(imageData == NULL)
		printf("Texture loading failed\n");

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);

    glActiveTexture(GL_TEXTURE0);
    //glBindTexture(GL_TEXTURE_2D, texture);
}

void Text2d::setText(const char* format, ...) {
    va_list args;
    str = new char[strlen(format)];

    va_start(args, format);
    vsnprintf(str, strlen(format), format, args);
    va_end(args);

    for(unsigned int i = 0; i < strlen(str); ++i) {
        vertices.push_back(glm::vec2(_x + i * _size,        _y + _size));
        vertices.push_back(glm::vec2(_x + i * _size+_size,  _y + _size));
        vertices.push_back(glm::vec2(_x + i * _size+_size,  _y));
        vertices.push_back(glm::vec2(_x + i * _size,        _y));

        char character = str[i];
        float uv_x = (character%10)/10.0;
        float uv_y = (character/10)/10.0;

        UVs.push_back(glm::vec2(uv_x,               1.0 - uv_y));
        UVs.push_back(glm::vec2(uv_x + 1.0/10.0,    1.0 - uv_y));
        UVs.push_back(glm::vec2(uv_x + 1.0/10.0,    1.0 - (uv_y + 1.0/10.0)));
        UVs.push_back(glm::vec2(uv_x,               1.0 - (uv_y + 1.0/10.0)));
    }

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(UVs), &UVs, GL_STATIC_DRAW);
}

void Text2d::render() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
