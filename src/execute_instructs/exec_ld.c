/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_ld
*/

#include "my.h"

void exec_ld(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int offset = 2;
    char *params_type = get_params_type(vm, pc);
    int param1 = 0;
    int reg_nb = 0;

    param1 = get_param_value(vm, proc, params_type[0], offset);
    offset += compute_offset(params_type[0]);
    reg_nb = vm->mem[(pc + offset) % MEM_SIZE];
    proc->reg[reg_nb - 1] = param1;
    offset += 1;
    proc->carry = (param1 == 0) ? 1 : 0;
    proc->pc = (pc + offset) % MEM_SIZE;
    return;
}
