#include <stdio.h>
#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Window.h"

Window* w;
Renderer* r;
SDL_Event e;
bool isRunning;
double deltaTime, currentTime;
double lastTime = SDL_GetTicks();

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
                    break;
                case SDL_KEYUP:
                    //keyboard button released
                    break;
            }
        }

        w->ClearScreen();

        //update entity positions, do physics, etc here

        //rendering here
        r->RenderSquare(0, 0, 0.5, 0.5);

        w->SwapBuffers();
    }
}

int main(int, char**) {
    printf("hello world\n");
    //printf("%d\n", CLAMP(5, 0, 1));

    w = new Window("test", 800, 600);
    r = new Renderer();
    isRunning = true;
    GameLoop();

    delete w;
    delete r;

    return 0;
}
