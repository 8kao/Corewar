/*
** EPITECH PROJECT, 2025
** robotdecon
** File description:
** my_arraylen
*/

#include "../../include/my.h"

int my_arraylen(char **array)
{
    int len = 0;

    for (int i = 0; array[i]; i++) {
        len++;
    }
    return len;
}
