#include "Enemy.h"

const float InvaderEnemy::vertices[] = {
    -0.1, 0.1,
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

InvaderEnemy::InvaderEnemy() {}

void Entity::update(float deltaTime) {
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
