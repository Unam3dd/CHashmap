#include "chashmap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

hashmap_t *new_hashmap(void *key)
{
    hashmap_t *new_hash = (hashmap_t *)malloc(sizeof(hashmap_t));

    new_hash->key = key;
    new_hash->next = NULL;
    new_hash->prev = NULL;
    new_hash->value_field = new_value(NULL);

    return (new_hash);
}


void push_hashmap(hashmap_t **list, hashmap_t *new)
{
    (*list)->prev = new;
    new->next = *list;
    *list = new;
}

void pop_hashmap(hashmap_t **list)
{
    hashmap_t *next = (*list)->next;
    next->prev = (*list)->prev;
    free(*list);
    *list = next;
}

void free_hashmap(hashmap_t **list)
{
    hashmap_t *actual = *list;
    hashmap_t *next = NULL;

    while (actual) {
        free_value(&actual->value_field);
        next = actual->next;
        printf("%p hashmap is freed !\n", actual);
        free(actual);
        actual = next;
    }

    *list = NULL;
}

hashmap_t *get_hashmap(hashmap_t **list, void *key)
{
    hashmap_t *actual = *list;

    while (actual && !string_compare(actual->key, key))
        actual = actual->next;
    
    return (actual);
}