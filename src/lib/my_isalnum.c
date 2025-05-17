/*
** EPITECH PROJECT, 2025
** test
** File description:
** my_isalnum
*/

#include "../../include/my.h"

int my_isalnum(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        (c >= 'a' && c <= 'z')) {
            return 0;
    } else {
        return 1;
    }
}
