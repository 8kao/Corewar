/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** dump_cycles
*/

#include "my.h"

void dump_mem(vm_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        my_printf("%x", vm->mem[i]);
    }
}

int dump_cycles(vm_t *vm)
{
    if (vm->last_alive_name) {
        my_printf("The player %d(%s) has won.\n", vm->last_alive_id,
            vm->last_alive_name);
    } else {
        my_printf("Nobody won.\n");
    }
    dump_mem(vm);
    return 0;
}
