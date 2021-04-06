#include "chashmap.h"
#include <stdlib.h>
#include <stdio.h>

value_key_t *new_value(void *value)
{
    value_key_t *ptr = (value_key_t *)malloc(sizeof(value_key_t));

    ptr->value = value;
    ptr->next = NULL;
    ptr->prev = NULL;
    ptr->index = 0;

    return (ptr);
}

void push_value(value_key_t **list, value_key_t *new)
{
    (*list)->prev = new;
    new->index = (*list)->index + 1;
    new->next = *list;
    *list = new;
}

void push_back_value(value_key_t **list, value_key_t *new)
{
    value_key_t *save = *list;

    while ((*list)->next)
        *list = (*list)->next;
    
    new->prev = *list;
    new->index = (*list)->index + 1;
    (*list)->next = new;

    *list = save;
}

value_key_t *get_value(value_key_t **list, int index)
{
    value_key_t *actual = *list;

    while (actual && actual->index != index)
        actual = actual->next;
    
    return (actual);
}

void set_value(value_key_t *field, void *value)
{
    field->value = value;
}

void replace_value(value_key_t **list, int index, void *value)
{
    value_key_t *actual = *list;

    while (actual && actual->index != index)
        actual = actual->next;
    
    actual->value = value;
}

void pop_value(value_key_t **list)
{
    value_key_t *next = (*list)->next;
    next->prev = (*list)->prev;
    next->index = (*list)->index - 1;
    free(*list);
    *list = next;
}

void pop_back(value_key_t **list)
{
    value_key_t *actual = *list;

    while (actual->next)
        actual = actual->next;
    
    actual->prev->next = NULL;
    free(actual);
}

void free_value(value_key_t **list)
{
    value_key_t *next = NULL;
    
    while (*list) {
        next = (*list)->next;
        printf("%p is freed !\n", *list);
        free(*list);
        *list = next;
    }

    *list = NULL;
}

void show_value(value_key_t *field, char type)
{
    switch (type) {
        case 's': printf("[%d] -> %s\n", field->index, (char *)field->value); break;
        case 'd': printf("[%d] -> %d\n", field->index, (int *)field->value); break;
        case 'l': printf("[%d] -> %ld\n", field->index, (long *)field->value); break;
        case 'i': printf("[%d] -> %d\n", field->index, (int *)field->value); break;
        case 'f': printf("[%d] -> %f\n", field->index, (int *)field->value); break;
        default: printf("[-] Error format !\n"); break;
    }
}