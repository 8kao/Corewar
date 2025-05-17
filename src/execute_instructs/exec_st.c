/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_st
*/

#include "my.h"

void exec_st(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int offset = 2;
    char *params_type = get_params_type(vm, pc);
    int reg1_value = 0;

    reg1_value = get_param_value(vm, proc, params_type[0], offset);
    offset += compute_offset(params_type[0]);
    if (params_type[1] == 3)
    write_value_to_ind_addr(vm, proc, offset, reg1_value);
    else
        write_value_in_reg(vm, proc, offset, reg1_value);
    offset += compute_offset(params_type[1]);
    proc->pc = (pc + offset) % MEM_SIZE;
    return;
}
