#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include "Renderer.h"
#include "Window.h"
#include "Entity.h"
#include "Enemy.h"

Window* w;
Renderer* r;
SDL_Event e;
bool isRunning;
double deltaTime, currentTime, lastTime;
const double FPS = 1.0/60.0;
const Uint8* keyState;
int width, height;

float x = 0.0, y = 0.0;
InvaderEnemy* ent1;
WandererEnemy* ent2;

void GameStart() {
    isRunning = true;
    lastTime = SDL_GetTicks();
    keyState = SDL_GetKeyboardState(NULL);

    while(isRunning) {
        currentTime = SDL_GetTicks();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        //TODO: generate set of pressed keys
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }

        // Retrieve user input
        //SDL_PumpEvents();

        if (keyState[SDL_SCANCODE_A])
            ent1->setVelocity(ent1->getVelX(), ent1->getVelY(), 0.005);
        if (keyState[SDL_SCANCODE_D])
            ent1->setVelocity(ent1->getVelX(), ent1->getVelY(), -0.005);
        if (keyState[SDL_SCANCODE_W])
            ent1->setVelocity(ent1->getVelX(), 0.001, ent1->getAngVel());
        if (keyState[SDL_SCANCODE_S])
            ent1->setVelocity(ent1->getVelX(), -0.001, ent1->getAngVel());

        if (keyState[SDL_SCANCODE_ESCAPE])
            isRunning = false;

        // Update entity positions, do physics, etc here
        ent1->update(deltaTime);

        glClearColor(0.1, 0.1, 0.1, 1.0);
        w->ClearScreen();

        //rendering here
        r->render();

        w->SwapBuffers();

        if(FPS - deltaTime > 0)
            SDL_Delay(FPS - deltaTime);
    }
}

int main(int, char**) {

    width = 512;
    height = 512;
    w = new Window("Geometry", width, height);
    r = new Renderer(width, height);

    ent1 = new InvaderEnemy();
    ent2 = new WandererEnemy();
    r->registerEntity(ent1);
    r->registerEntity(ent2);
    r->attachEntity(ent1);
    ent2->translate(0.5, 0.5);

    GameStart();

    delete w;
    delete r;

    return 0;
}
