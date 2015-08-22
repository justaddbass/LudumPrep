#ifndef ENTITY_H
#define ENTITY_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Entity {
public:
    Entity();
    ~Entity();

    inline const glm::mat4 getModelMatrix() const {return model_matrix;}
    void update(float deltaTime);
    void translate(float x, float y);
    void rotate(float angle);
    void setVelocity(float vel_x, float vel_y, float ang_vel);
    void render();
    inline const float getVelX() const {return _vel_x;}
    inline const float getVelY() const {return _vel_y;}
    inline const float getAngVel() const {return _ang_vel;}
    inline const float getX() const {return model_matrix[3][0];}
    inline const float getY() const {return model_matrix[3][1];}
private:
    const float THRESHOLD = 1.0/100000.0;
    float _vel_x, _vel_y, _ang_vel;
    static const float vertices[];
    static const float vertex_colors[];
    glm::mat4 model_matrix;
    GLuint vao, vbo, colorBuffer;
};

#endif
