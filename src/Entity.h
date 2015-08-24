#ifndef ENTITY_H
#define ENTITY_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Entity {
public:
    Entity();
    virtual ~Entity() {}

    virtual inline const glm::mat4 getModelMatrix() const {return model_matrix;}
    virtual void update(float deltaTime) = 0;
    virtual void translate(float x, float y) = 0;
    virtual void rotate(float angle) = 0;
    virtual void setVelocity(float vel_x, float vel_y, float ang_vel) = 0;
    virtual void render() = 0;
    virtual bool loadOBJ(const char *path) = 0;
    virtual inline const float getVelX() const {return _vel_x;}
    virtual inline const float getVelY() const {return _vel_y;}
    virtual inline const float getAngVel() const {return _ang_vel;}
    virtual inline const float getX() const {return model_matrix[3][0];}
    virtual inline const float getY() const {return model_matrix[3][1];}
protected:
    const float THRESHOLD = 1.0/100000.0;
    float _vel_x, _vel_y, _ang_vel;
    unsigned long long created_at;
    glm::mat4 model_matrix;
    GLuint vao, vbo, colorBuffer;
private:
    const int vertex_count = 3;
    // Using vectors for deferred initialization
    std::vector<glm::vec2> *vertices;
    std::vector<glm::vec3> *vertex_colors;
};

#endif
