/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strcspn
*/

#include "../../include/my.h"

static size_t is_reject(char c, const char *reject)
{
    for (size_t j = 0; reject[j]; j++) {
        if (c == reject[j])
            return 1;
    }
    return 0;
}

size_t my_strcspn(const char *str, const char *reject)
{
    size_t i = 0;

    while (str[i]) {
        if (is_reject(str[i], reject) == 1)
            return i;
        i++;
    }
    return i;
}
