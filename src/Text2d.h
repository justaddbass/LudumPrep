#ifndef TEXT2D_H
#define TEXT2D_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
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
    GLuint vao, vertex_buffer, uv_buffer, texture;
    std::vector<glm::vec2> vertices;
    std::vector<glm::vec2> UVs;
    float _x, _y;
    int _size;
    char* str;
};

#endif
