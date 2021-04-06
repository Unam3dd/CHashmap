#include "chashmap.h"
#include <stdio.h>

int main(void)
{
    hashmap_t *hash = new_hashmap("test");
    hashmap_t *new_hashm = new_hashmap("test2");
    value_key_t *next_value = new_value((int *)2);

    set_value(hash->value_field, "memory");
    push_back_value(&hash->value_field, next_value);

    show_value(hash->value_field->next, 'd');

    set_value(new_hashm->value_field, "new_memory");
    push_hashmap(&hash, new_hashm);

    hashmap_t *get_hash = get_hashmap(&hash, "test");

    printf("%s\n", (char *)get_hash->value_field->value);

    free_hashmap(&hash);

    return (0);
}