/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_o
*/

#include "../../../include/my_printf.h"

static int my_octal_nbr(long int nb)
{
    if (nb >= 8)
        my_octal_nbr(nb / 8);
    my_putchar((nb % 8) + 48);
}

void flag_lo(va_list args, int *pntr)
{
    my_octal_nbr((long int)va_arg(args, long int));
}
