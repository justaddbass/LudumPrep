#include "Renderer.h"
#include "Shaders.h"
#include <stdio.h>

Renderer::Renderer() {
    program = LoadShaders("res/vshader.vs", "res/fshader.fs");
    glUseProgram(program);
    view_model_matrix_handle = glGetUniformLocation(program, "VM");
}

void Renderer::render() {

    for(std::vector<Entity*>::iterator i = entities.begin(); i < entities.end(); ++i)
    {
        model_matrix = (*i)->getModelMatrix();
        UpdateMatrices();
        (*i)->render();
    }
}

void Renderer::UpdateMatrices() {
    position = glm::vec3(0.0, 0.0, 1.0);
    up = glm::vec3(0.0, 1.0, 0.0);
    direction = glm::vec3(0.0, 0.0, -1.0);

    view_matrix = glm::lookAt(position, position + direction, up);
    //glm::mat4 model_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0));

    view_model_matrix = view_matrix * model_matrix;
    glUniformMatrix4fv(view_model_matrix_handle, 1, GL_FALSE, &view_model_matrix[0][0]);
}

void Renderer::registerEntity(Entity* ent) {
    entities.push_back(ent);
}

void Renderer::attachEntity(Entity* ent) {
    attached_entity = ent;
}
