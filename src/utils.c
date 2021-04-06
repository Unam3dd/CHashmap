#include "chashmap.h"


uint64_t string_len(const char *str)
{
    uint64_t n = 0;

    while (*(str)++)
        n++;
    
    return (n);
}

bool string_compare(const char *str1, const char *str2)
{
    if (string_len(str1) != string_len(str2))
        return (0);
    
    while (*str1 && *str2)
        if (*(str1)++ != *(str2)++)
            return (0);
    
    return (1);
}