/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_bytes
*/

#include "my.h"

int read_bytes(vm_t *vm, int addr, int size)
{
    int result = 0;

    for (int i = 0; i < size; i++) {
        result <<= 8;
        result |= vm->mem[(addr + i) % MEM_SIZE];
    }
    return result;
}
