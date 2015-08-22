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

    virtual inline const glm::mat4 getModelMatrix() const {return model_matrix;}
    virtual void update(float deltaTime) = 0;
    virtual void translate(float x, float y);
    virtual void rotate(float angle);
    virtual void setVelocity(float vel_x, float vel_y, float ang_vel);
    virtual void render();
    virtual inline const float getVelX() const {return _vel_x;}
    virtual inline const float getVelY() const {return _vel_y;}
    virtual inline const float getAngVel() const {return _ang_vel;}
    virtual inline const float getX() const {return model_matrix[3][0];}
    virtual inline const float getY() const {return model_matrix[3][1];}
protected:
    const float THRESHOLD = 1.0/100000.0;
    float _vel_x, _vel_y, _ang_vel;
    glm::mat4 model_matrix;
    GLuint vao, vbo, colorBuffer;
private:
    static const float vertices[];
    static const float vertex_colors[];
};

#endif
