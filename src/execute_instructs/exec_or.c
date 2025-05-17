/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_or
*/

#include "my.h"

void exec_or(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int offset = 2;
    char *params_type = get_params_type(vm, pc);
    int param1 = 0;
    int param2 = 0;
    int reg_nb = 0;

    param1 = get_param_value(vm, proc, params_type[0], offset);
    offset += compute_offset(params_type[0]);
    param2 = get_param_value(vm, proc, params_type[1], offset);
    offset += compute_offset(params_type[1]);
    reg_nb = vm->mem[(pc + offset) % MEM_SIZE];
    proc->reg[reg_nb - 1] = param1 | param2;
    offset += compute_offset(params_type[2]);
    proc->carry = (param1 | param2 == 0) ? 1 : 0;
    proc->pc = (pc + offset) % MEM_SIZE;
    return;
}
