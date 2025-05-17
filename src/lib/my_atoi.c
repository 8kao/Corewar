/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** my_atoi
*/

#include "../../include/my.h"

int my_atoi(char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    if (str[0] == '-')
        sign = -1;
    while (str[i] >= 48 && str[i] <= 57) {
        result *= 10;
        result += ((int)str[i] - 48);
        i++;
    }
    return result * sign;
}
