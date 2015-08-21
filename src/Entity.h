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
    void update();
    void translate(float x, float y);
    void setVelocity(float vel_x, float vel_y);
    void render();
    inline const float getVelX() const {return _vel_x;}
    inline const float getVelY() const {return _vel_y;}
    inline const float getX() const {return model_matrix[3][0];}
    inline const float getY() const {return model_matrix[3][1];}
private:
    float _vel_x, _vel_y;
    static const float vertices[];
    glm::mat4 model_matrix;
    GLuint vao, vbo;
};

#endif
