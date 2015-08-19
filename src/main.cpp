#include <stdio.h>
#include "Renderer.h"
#include "Window.h"


int main(int, char**) {
    printf("hello world\n");
    printf("%d\n", CLAMP(5, 0, 1));

    Window* w = new Window("test", 800, 600);
    Renderer r;
    w->ClearScreen();
    r.RenderSquare(0,0,0.5,0.75);
    //r.RenderScene();
    w->SwapBuffers();
    delete w;
    return 0;
}
