#include <stdio.h>
#include "Renderer.h"
#include "Window.h"


int main(int, char**) {
    printf("hello world\n");
    printf("%d\n", CLAMP(5, 0, 1));

    Window window("test", 800, 600);
    Renderer r;
    // r.RenderSquare(0,0,0,0);
    r.RenderScene();
    window.SwapBuffers();

    return 0;
}
