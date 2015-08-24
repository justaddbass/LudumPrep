#include "Enemy.h"
#include "SDL.h"
#include <math.h>

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

/**
 * Wanderer Enemy
 */

void WandererEnemy::update(float deltaTime) {
    translate(_vel_x * deltaTime, _vel_y * deltaTime);
    // Calculate elapsed time in seconds
    float t = (float)(SDL_GetPerformanceCounter() - created_at) / (float)SDL_GetPerformanceFrequency();
    _ang_vel = 0.01 * sin(t / 3.0);
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
