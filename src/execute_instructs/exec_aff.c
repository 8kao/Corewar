/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_aff
*/

#include "my.h"

void exec_aff(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int reg_value = get_param_value(vm, proc, 1, 2);

    my_printf("%c\n", reg_value);
    proc->pc = (pc + 3) % MEM_SIZE;
    return;
}
