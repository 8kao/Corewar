/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_s
*/

#include "../../../include/my_printf.h"

void flag_s(va_list args, int *pntr)
{
    my_putstr((char *)va_arg(args, char *));
}
