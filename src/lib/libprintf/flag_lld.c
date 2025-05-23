/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_lld
*/

#include "../../../include/my_printf.h"

static long long int my_put_long_long(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb <= 9)
        my_putchar(nb + 48);
    else {
        my_put_long_long(nb / 10);
        my_put_long_long(nb % 10);
    }
    return (0);
}

void flag_lld(va_list args, int *pntr)
{
    my_put_long_long((long long int)va_arg(args, long long int));
}
