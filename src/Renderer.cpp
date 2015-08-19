#include "Renderer.h"
#include "Shaders.h"
#include <stdio.h>

Renderer::Renderer() {
    program = LoadShaders("res/vshader.vs", "res/fshader.fs");
    glUseProgram(program);
    view_model_matrix_handle = glGetUniformLocation(program, "VM");
}

void Renderer::RenderSquare(float x, float y, float width, float height) {
    static const GLfloat vertex_data[] = {
        -0.5, 0.5,
        -0.5, -0.5,
        0.5, -0.5,
        0.5, 0.5
    };

    GLuint vao, vertex_buffer, color_buffer;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    UpdateMatrices(x, y);
    // glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glLineWidth(2.0f);
    glDrawArrays(GL_LINE_LOOP, 0, 4);

    glDisableVertexAttribArray(0);
}

void Renderer::UpdateMatrices(float x, float y) {
    position = glm::vec3(0.0, 0.0, 1.0);
    up = glm::vec3(0.0, 1.0, 0.0);
    direction = glm::vec3(0.0, 0.0, -1.0);

    view_matrix = glm::lookAt(position, position + direction, up);
    glm::mat4 model_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0));

    view_model_matrix = view_matrix * model_matrix;
    //view_model_matrix = glm::mat4(1.0);
    glUniformMatrix4fv(view_model_matrix_handle, 1, GL_FALSE, &view_model_matrix[0][0]);
}
