/*
** EPITECH PROJECT, 2024
** Piscine jour 7
** File description:
** My Library - String
*/

#include "../../include/my.h"

char *my_strdup(char const *str)
{
    char *new_str;

    if (!str)
        return NULL;
    new_str = malloc((my_strlen(str) + 1) * sizeof(char));
    my_strcpy(new_str, str);
    return new_str;
}
