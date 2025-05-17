/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** ok
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ')
        i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else
            break;
    }
    return result * sign;
}
