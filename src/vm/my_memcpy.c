/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** my_memcpy
*/

#include "my.h"

void my_memcpy(void *dest, const void *src, size_t size)
{
    unsigned char *csrc = (unsigned char *)src;
    unsigned char *cdest = (unsigned char *)dest;

    for (int i = 0; i < size; i++) {
        cdest[i] = csrc[i];
    }
}
