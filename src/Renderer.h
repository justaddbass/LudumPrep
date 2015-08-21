#ifndef RENDERER_H
#define RENDERER_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Entity.h"
#include <vector>

//#define CLAMP(A, LOWER, UPPER) (A > LOWER && A < UPPER) ? (A) : (A < LOWER ? (LOWER) : (UPPER))

typedef struct {
    int x, y;
} Camera;

class Renderer {
public:
    Renderer();
    ~Renderer() {}
    void render();
    void registerEntity(Entity* ent);
    void attachEntity(Entity* ent);
    void UpdateMatrices();
private:
    GLuint view_model_matrix_handle, program;
    glm::vec3 position, direction, up;
    glm::mat4 model_matrix, view_matrix, view_model_matrix;
    Entity* attached_entity;
    std::vector<Entity*> entities;
};

#endif
