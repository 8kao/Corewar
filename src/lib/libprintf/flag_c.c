/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_c
*/

#include "../../../include/my_printf.h"

void flag_c(va_list args, int *pntr)
{
    my_putchar((char)va_arg(args, int));
}
