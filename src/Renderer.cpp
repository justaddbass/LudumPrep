#include "Renderer.h"
#include <stdio.h>

Renderer::Renderer(int w, int h) {
    //textureShader->registerUniform("VM");

    width = w;
    height = h;
}

void Renderer::render() {

    for(std::vector<Entity*>::iterator i = entities.begin(); i < entities.end(); ++i)
    {
        updateViewMatrix();
        model_matrix = (*i)->getModelMatrix();
        view_model_matrix = view_matrix * model_matrix;

        //sets uniforms for both shaders, definitely better way to do this
        currentShader->setUniformMatrix4fv("VM", &view_model_matrix[0][0]);
        currentShader->setUniform1i("texSampler", 0);
        (*i)->render();
    }
}

void Renderer::setShader(Shader *shader) {
    shader->setCurrent();
    currentShader = shader;
}

void Renderer::updateViewMatrix() {
    position = glm::vec3(attached_entity->getX(), attached_entity->getY(), 1.0);
    // position = glm::vec3(0.0, 0.0, 1.0);
    up = glm::vec3(0.0, 1.0, 0.0);
    direction = glm::vec3(0.0, 0.0, -1.0);
    view_matrix = glm::lookAt(position, position + direction, up);
}

void Renderer::createFramebuffer(GLuint &fbo, GLuint &fbtex) {
    glGenTextures(1, &fbtex);
    glBindTexture(GL_TEXTURE_2D, fbtex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbtex, 0);
    {
        GLenum status;
        status = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
        switch (status) {
            case GL_FRAMEBUFFER_COMPLETE:
                break;
            case GL_FRAMEBUFFER_UNSUPPORTED:
                printf("Error: unsupported framebuffer format\n");
                exit(0);
            default:
                printf("Error: invalid framebuffer config\n");
                exit(0);
        }
    }
}

void Renderer::registerEntity(Entity* ent) {
    entities.push_back(ent);
}

void Renderer::attachEntity(Entity* ent) {
    attached_entity = ent;
}
