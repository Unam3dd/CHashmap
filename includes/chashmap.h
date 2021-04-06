#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef _WIN32
#pragma warning(disable:4477)
#pragma warning(disable:4313)
#endif

///////////////////////////////////////////////////
//      HASHMAP struct                           //
///////////////////////////////////////////////////
typedef struct value_key
{
    int index;
    void *value;
    struct value_key *next;
    struct value_key *prev;
} value_key_t;

typedef struct hashmap
{
    void *key;
    value_key_t *value_field;
    struct hashmap *next;
    struct hashmap *prev;
} hashmap_t;

// value.c
value_key_t *new_value(void *value);
void push_value(value_key_t **list, value_key_t *new);
void push_back_value(value_key_t **list, value_key_t *new);
value_key_t *get_value(value_key_t **list, int index);
void replace_value(value_key_t **list, int index, void *value);
void set_value(value_key_t *field, void *value);
void pop_value(value_key_t **list);
void pop_back(value_key_t **list);
void free_value(value_key_t **list);
void show_value(value_key_t *field, char type);

// hashmap.c
hashmap_t *new_hashmap(void *key);
void push_hashmap(hashmap_t **list, hashmap_t *new);
void pop_hashmap(hashmap_t **list);
void free_hashmap(hashmap_t **list);
hashmap_t *get_hashmap(hashmap_t **list, void *key);

// utils.c
uint64_t string_len(const char *str);
bool string_compare(const char *str1, const char *str2);