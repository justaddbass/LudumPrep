#include <stdio.h>
#include "Renderer.h"

int main(int, char**) {
    printf("hello world\n");
    printf("%d\n", CLAMP(5, 0, 1));

    return 0;
}
