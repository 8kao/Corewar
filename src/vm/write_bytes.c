/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** write_bytes
*/

#include "my.h"

void write_bytes(vm_t *vm, int addr, int value, int size)
{
    for (int i = 0; i < size; i++) {
        vm->mem[(addr + size - 1 - i) % MEM_SIZE] = (value >> (i * 8)) & 0xFF;
    }
}
