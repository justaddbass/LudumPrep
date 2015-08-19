#include "Renderer.h"
#include "Shaders.h"

Renderer::Renderer() {
    program = LoadShaders("res/vshader.vs", "res/fshader.fs");
    glUseProgram(program);
}

void Renderer::RenderSquare(float x, float y, float width, float height) {
    static const GLfloat vertex_data[] = {
        //0.0f, 0.0f, 0.0f,
        x-(width/2), y+(height/2), 0.0f,
        x-(width/2), y-(height/2), 0.0f,
        x+(width/2), y+(height/2), 0.0f,
        x+(width/2), y-(height/2), 0.0f,
    };

    GLuint vao, vertex_buffer, color_buffer;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableVertexAttribArray(0);
}
