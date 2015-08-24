#include "Entity.h"
#include "SDL.h"
#include <stdio.h>

Entity::Entity() {
    model_matrix = glm::mat4(1.0);
    _vel_x = 0.0;
    _vel_y = 0.0;
    _ang_vel = 0.0;
    created_at = SDL_GetPerformanceCounter();

    if (!loadOBJ("res/mesh/Entity.obj")) {
        printf("Failed to initialize Entity.");
        return;
    }

    for (int i = 0; i < vertex_count; i++) {
        vertex_colors->push_back(glm::vec3(1.0, 1.0, 1.0));
    };

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(glm::vec2), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_colors), vertex_colors, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, vertex_colors->size() * sizeof(glm::vec3), &vertex_colors[0], GL_STATIC_DRAW);
}

void Entity::translate(float x, float y) {
    model_matrix = glm::translate(model_matrix, glm::vec3(x, y, 0));
}

void Entity::rotate(float angle) {
    model_matrix = glm::rotate(model_matrix, angle, glm::vec3(0, 0, 1));
}

void Entity::setVelocity(float vel_x, float vel_y, float ang_vel) {
    _vel_x = vel_x;
    _vel_y = vel_y;
    _ang_vel = ang_vel;
}

void Entity::render() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glLineWidth(2.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
}

bool Entity::loadOBJ(const char *path) {
    std::vector<unsigned int> vertexIndices;
    std::vector<glm::vec2> temp_vertices;

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Failed to open the file!\n");
        return false;
    }

    while (1) {
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.
        
        // else: parse lineHeader
        if (strcmp(lineHeader, "v") == 0) {
            glm::vec2 vertex;
            fscanf(file, "%f %f\n", &vertex.x, &vertex.y);
            temp_vertices.push_back(vertex);
        } else if (strcmp(lineHeader, "l") == 0) {
            // std::string vertex1, vertex2;
            unsigned int vertexIndex[2];
            int matches = fscanf(file, "%d/%d\n", &vertexIndex[0], &vertexIndex[1]);
            if (matches != 2) {
                printf("Error parsing OBJ file \"%s\".\n", path);
                return false;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);

            // For each vertex of each line
            for (unsigned int i = 0; i < vertexIndices.size(); i++) {
                unsigned int vertexIndex = vertexIndices[i];
                glm::vec2 vertex = temp_vertices[vertexIndex - 1];
                vertices->push_back(vertex);
            }
        }
    }
    
    return true;
}
