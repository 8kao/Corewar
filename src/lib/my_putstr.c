/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** ok
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int my_putstr_error(char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}
