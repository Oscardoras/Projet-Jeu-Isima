#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "level.h"


Level* new_level(float width, float length) {
    Level* level = malloc(sizeof(Level));
    if (level) {
        level->width = width;
        level->length = length;
    }
    return level;
}

void free_level(Level* level) {
    for (struct EntityListCell* it = level->entities; it != NULL;) {
        struct EntityListCell* tmp = it;
        it = it->next;
        free_entity(tmp->entity);
        free(tmp);
    }
    free(level);
}

bool add_level_entity(Level* level, Entity* entity) {
    struct EntityListCell* cell = malloc(sizeof(struct EntityListCell));
    if (cell) {
        cell->entity = entity;
        cell->next = level->entities;
        level->entities = cell;
        return true;
    } else return false;
}