#include "Text2d.h"

Text2d::Text2d(float x, float y, int size) {
    _x = x;
    _y = y;
    _size = size;
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
        float uv_x = (character%16)/16.0;
        float uv_y = (character/16)/16.0;

        UVs.push_back(glm::vec2(uv_x,               1.0 - uv_y));
        UVs.push_back(glm::vec2(uv_x + 1.0/16.0,    1.0 - uv_y));
        UVs.push_back(glm::vec2(uv_x + 1.0/16.0,    1.0 - (uv_y + 1.0/16.0)));
        UVs.push_back(glm::vec2(uv_x,               1.0 - (uv_y + 1.0/16.0)));
    }
}

void Text2d::render() {

}
