/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_x_up
*/

#include "../../../include/my_printf.h"

void flag_x_up(va_list args, int *pntr)
{
    my_put_nbr_base((int)va_arg(args, int), "0123456789ABCDEF");
}
