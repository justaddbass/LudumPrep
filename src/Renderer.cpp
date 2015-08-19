#include "Renderer.h"
#include "Shaders.h"

Renderer::Renderer() {
    program = LoadShaders("res/vshader.vs", "res/fshader.fs");
    glUseProgram(program);
    view_matrix_handle = glGetUniformLocation(program, "V");
    model_matrix_handle = glGetUniformLocation(program, "M");
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

void Renderer::RenderScene() {
    glUniformMatrix4fv(view_matrix_handle, 1, GL_FALSE, &view_matrix[0][0]);
    // glUniformMatrix4fv(projectionID, 1, GL_FALSE, &projection_matrix[0][0]);
    
    position = glm::vec3(0.0, 0.0, -50.0);
    up = glm::vec3(0.0, 1.0, 0.0);
    direction = glm::vec3(0.0, 0.0, 1.0);

    view_matrix = glm::lookAt(position, position + direction, up);
    glm::mat4 model_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, 0.0));
    glUniformMatrix4fv(model_matrix_handle, 1, GL_FALSE, &model_matrix[0][0]);
    
}
