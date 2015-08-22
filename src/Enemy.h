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

class InvaderEnemy: Entity {
public:
    InvaderEnemy();
    ~InvaderEnemy();
    void update(float deltaTime);
private:
	static const float vertices[];
	static const float vertex_colors[];
};

#endif
