#ifndef RENDERER_H
#define RENDERER_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define CLAMP(A, LOWER, UPPER) (A > LOWER && A < UPPER) ? (A) : (A < LOWER ? (LOWER) : (UPPER))

typedef struct {
    int x, y;
} Camera;

class Renderer {
public:
    Renderer();
    ~Renderer() {}
    void RenderSquare(float x, float y, float width, float height);
    void UpdateMatrices();
private:
    GLuint view_model_matrix_handle, program;
    glm::vec3 position, direction, up;
    glm::mat4 view_matrix, view_model_matrix;
};

#endif
