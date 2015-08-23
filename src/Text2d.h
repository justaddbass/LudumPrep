#ifndef TEXT2D_H
#define TEXT2D_H

#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <vector>
#include <glm/glm.hpp>

class Text2d {
public:
    Text2d() {}
    Text2d(float x, float y, int size);

    void setText(const char* format, ...);
    void render();
private:
    std::vector<glm::vec2> vertices;
    std::vector<glm::vec2> UVs;
    float _x, _y;
    int _size;
    char str[128];
};

#endif
