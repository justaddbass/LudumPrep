#include "Enemy.h"

const float InvaderEnemy::vertices[] = {
    -0.1, 0.25,
    -0.1, -0.1,
    0.1, 0.1,
    0.1, -0.1
};

const float InvaderEnemy::vertex_colors[] = {
	0.0, 1.0, 1.0,
	0.0, 1.0, 1.0,
	0.0, 1.0, 1.0,
	0.0, 1.0, 1.0
};

InvaderEnemy::InvaderEnemy() {
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

void InvaderEnemy::update(float deltaTime) {
    translate(_vel_x * deltaTime, _vel_y * deltaTime);
    rotate(_ang_vel * deltaTime);

    if(_vel_x > THRESHOLD)
        _vel_x -= THRESHOLD;
    else if(_vel_x < -THRESHOLD)
        _vel_x += THRESHOLD;
    else
        _vel_x = 0.0;
    if(_vel_y > THRESHOLD)
        _vel_y -= THRESHOLD;
    else if(_vel_y < -THRESHOLD)
        _vel_y += THRESHOLD;
    else
        _vel_y = 0.0;
    if(_ang_vel > THRESHOLD * 100.0)
        _ang_vel -= THRESHOLD * 100.0;
    else if(_ang_vel < -THRESHOLD * 100.0)
        _ang_vel += THRESHOLD * 100.0;
    else
        _ang_vel = 0.0;
}
