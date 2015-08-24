#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <vector>

// class Enemy: protected Entity {
// public:
//     Enemy();
//     ~Enemy();
// };

class WandererEnemy : public Entity {
public:
	WandererEnemy() : Entity() {}
	~WandererEnemy() {}
	void update(float deltaTime);
    void translate(float x, float y) {Entity::translate(x, y);}
    void rotate(float angle) {Entity::rotate(angle);}
    void setVelocity(float vel_x, float vel_y, float ang_vel) {Entity::setVelocity(vel_x, vel_y, ang_vel);}
    void render() {Entity::render();}
    bool loadOBJ(const char *path) { return Entity::loadOBJ(path); };
private:
	Entity *ent;
	const int vertex_count = 12;
    // Using optional for deferred initialization (without pointers)
    std::vector<glm::vec2> *vertices;
    std::vector<glm::vec3> *vertex_colors;
};

class InvaderEnemy : public Entity {
public:
    InvaderEnemy() : Entity() {}
    ~InvaderEnemy() {}
    void update(float deltaTime);
    void translate(float x, float y) {Entity::translate(x, y);}
    void rotate(float angle) {Entity::rotate(angle);}
    void setVelocity(float vel_x, float vel_y, float ang_vel) {Entity::setVelocity(vel_x, vel_y, ang_vel);}
    void render() {Entity::render();}
    bool loadOBJ(const char *path) { return Entity::loadOBJ(path); };
private:
	const int vertex_count = 4;
    // Using vector for deferred initialization
    std::vector<glm::vec2> *vertices;
    std::vector<glm::vec3> *vertex_colors;
};

#endif
