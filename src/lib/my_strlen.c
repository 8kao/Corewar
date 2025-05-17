/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** ok
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}
