/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** get_params_type
*/

#include "my.h"

char *get_params_type(vm_t *vm, int pc)
{
    static char type_tab[3];
    unsigned coding_byte = vm->mem[(pc + 1) % MEM_SIZE];

    for (int i = 0; i < 3; i++) {
        type_tab[i] = (coding_byte >> (6 - 2 * i)) & 0b11;
    }
    return type_tab;
}
