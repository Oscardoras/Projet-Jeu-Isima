#include "level.h"
#include <stdbool.h>

Level* new_level(float width, float lenght)
{
    Level* newLevel =  (Level*)malloc(sizeof(Level));
    if(newLevel)
    {
        newLevel->width = width;
        newLevel->length = length;
    }
    return newLevel;
}

void free_level(Level* level)
{
    EntityListCell * next;
    for(EntityListCell * iterator = level->entities; iterator; iterator = next)
    {
        free_entity(iterator->entity);
        next = iterator->cell;
        free(iterator);
    }
    free(level);
}

bool add_level_entity(Level* level, Entity* entity)
{
    EntityListCell * newEntity = (EntityListCell *)malloc(sizeof(EntityListCell));
    if(newEntity)
    {
        newEntity->entity = entity;
        newEntity->cell = level->entities;
        level->entities = newEntity;
        return true;
    }
    return false;
}