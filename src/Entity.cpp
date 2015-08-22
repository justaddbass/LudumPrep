#include "Entity.h"

const float Entity::vertices[] = {
    0.0, 0.1,
    0.1, -0.1,
    -0.1, -0.1,
    0.0, 0.1,
};

const float Entity::vertex_colors[] = {
    1.0, 1.0, 1.0,
    1.0, 1.0, 1.0,
    1.0, 1.0, 1.0,
    1.0, 1.0, 1.0
};

Entity::Entity() {
    model_matrix = glm::mat4(1.0);
    _vel_x = 0.0;
    _vel_y = 0.0;
    _ang_vel = 0.0;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_colors), vertex_colors, GL_STATIC_DRAW);
}

Entity::~Entity() {

}

void Entity::translate(float x, float y) {
    model_matrix = glm::translate(model_matrix, glm::vec3(x ,y ,0));
}

void Entity::rotate(float angle) {
    model_matrix = glm::rotate(model_matrix, angle, glm::vec3(0, 0, 1));
}

void Entity::setVelocity(float vel_x, float vel_y, float ang_vel) {
    _vel_x = vel_x;
    _vel_y = vel_y;
    _ang_vel = ang_vel;
}

void Entity::render() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glLineWidth(2.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
}
