#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

// class Enemy: protected Entity {
// public:
//     Enemy();
//     ~Enemy();
// };

// class WandererEnemy extends Enemy {
//     WandererEnemy() {
//         vertices[24] = {
//             0.0, 0.1,
//             -0.1, 0.1,
//             0.0, 0.0,
//             -0.1, 0.0,
//             -0.1, -0.1,
//             0.0, 0.0,
//             0.0, -0.1,
//             0.1, -0.1,
//             0.0, 0.0,
//             0.1, 0.0,
//             0.1, 0.1,
//             0.0, 0.0
//         };
//     }
// };

class InvaderEnemy : public Entity {
public:
    InvaderEnemy();
    ~InvaderEnemy() {}
    void update(float deltaTime);
    void translate(float x, float y) {Entity::translate(x, y);}
    void rotate(float angle) {Entity::rotate(angle);}
    void setVelocity(float vel_x, float vel_y, float ang_vel) {Entity::setVelocity(vel_x, vel_y, ang_vel);}
    void render() {Entity::render();}
private:
	static const float vertices[];
	static const float vertex_colors[];
};

#endif
