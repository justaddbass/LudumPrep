#include "Entity.h"

const float Entity::vertices[] = {
    0.0, 0.1,
    0.1, -0.1,
    -0.1, -0.1,
    0.0, 0.1,
};

Entity::Entity() {
    model_matrix = glm::mat4(1.0);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

Entity::~Entity() {

}

void Entity::update() {
    model_matrix[3][0] += _vel_x;
    model_matrix[3][1] += _vel_x;
}

void Entity::translate(float x, float y) {
    model_matrix = glm::translate(model_matrix, glm::vec3(x ,y ,0));
}

void Entity::setVelocity(float vel_x, float vel_y) {
    _vel_x = vel_x;
    _vel_y = vel_y;
}

void Entity::render() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glLineWidth(2.0f);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
}
