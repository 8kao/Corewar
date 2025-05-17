/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_sub
*/

#include "my.h"

void exec_sub(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int offset = 2;
    int reg1_value = 0;
    int reg2_value = 0;

    reg1_value = get_param_value(vm, proc, 1, offset);
    offset += 1;
    reg2_value = get_param_value(vm, proc, 1, offset);
    offset += 1;
    write_value_in_reg(vm, proc, offset, reg1_value - reg2_value);
    offset += 1;
    proc->pc = (pc + offset) % MEM_SIZE;
    proc->carry = ((reg1_value - reg2_value) == 0) ? 1 : 0;
    return;
}
