#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include "Renderer.h"
#include "Window.h"

Window* w;
Renderer* r;
SDL_Event e;
bool isRunning;
double deltaTime, currentTime;
double lastTime = SDL_GetTicks();
const double FPS = 1/60;
bool keys[4] = {false};

float x = 0, y = 0;

enum {
    W,
    A,
    S,
    D
};

void GameLoop() {
    currentTime = SDL_GetTicks();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    while(isRunning) {

        //TODO: generate set of pressed keys
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    //keyboard button pressed
                    switch(e.key.keysym.sym) {
                        case SDLK_w:
                            keys[W] = true;
                            break;
                        case SDLK_a:
                            keys[A] = true;
                            break;
                        case SDLK_s:
                            keys[S] = true;
                            break;
                        case SDLK_d:
                            keys[D] = true;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    //keyboard button released
                    switch(e.key.keysym.sym) {
                        case SDLK_w:
                            keys[W] = false;
                            break;
                        case SDLK_a:
                            keys[A] = false;
                            break;
                        case SDLK_s:
                            keys[S] = false;
                            break;
                        case SDLK_d:
                            keys[D] = false;
                            break;
                    }
                    break;
            }
        }

        w->ClearScreen();

        //update entity positions, do physics, etc here
        if(keys[W])
            y += 0.0001 * deltaTime;
        if(keys[A])
            x -= 0.0001 * deltaTime;
        if(keys[S])
            y -= 0.0001 * deltaTime;
        if(keys[D])
            x += 0.0001 * deltaTime;

        //rendering here
        r->RenderSquare(x, y, 0.5, 0.5);

        w->SwapBuffers();

        if(FPS - deltaTime > 0)
            SDL_Delay(FPS - deltaTime);
    }
}

int main(int, char**) {

    w = new Window("test", 800, 600);
    r = new Renderer();
    isRunning = true;
    GameLoop();

    delete w;
    delete r;

    return 0;
}
