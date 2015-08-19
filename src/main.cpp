#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include "Renderer.h"
#include "Window.h"

Window* w;
Renderer* r;
SDL_Event e;
bool isRunning;
double deltaTime, currentTime, lastTime;
const double FPS = 1.0/60.0;
const Uint8* keyState;

float x = 0.0, y = 0.0;

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
        SDL_PumpEvents();

        if (keyState[SDL_SCANCODE_A])
            x -= 0.0001 * deltaTime;
        if (keyState[SDL_SCANCODE_D])
            x += 0.0001 * deltaTime;
        if (keyState[SDL_SCANCODE_W])
            y += 0.0001 * deltaTime;
        if (keyState[SDL_SCANCODE_S])
            y -= 0.0001 * deltaTime;

        if (keyState[SDL_SCANCODE_ESCAPE])
            isRunning = false;

        // Update entity positions, do physics, etc here
        
        w->ClearScreen();

        //rendering here
        r->RenderSquare(x, y, 0.5, 0.5);

        w->SwapBuffers();

        if(FPS - deltaTime > 0)
            SDL_Delay(FPS - deltaTime);
    }
}

int main(int, char**) {

    w = new Window("Geometry", 800, 600);
    r = new Renderer();

    GameStart();

    delete w;
    delete r;

    return 0;
}
