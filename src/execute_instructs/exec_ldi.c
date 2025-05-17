/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_ldi
*/

#include "my.h"

void exec_ldi(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int offset = 2;
    char *params_type = get_params_type(vm, pc);
    int param1 = 0;
    int param2 = 0;
    int value = 0;

    param1 = get_param_value(vm, proc, params_type[0], offset);
    offset += compute_offset_specials(params_type[0]);
    param2 = get_param_value(vm, proc, params_type[1], offset);
    offset += compute_offset_specials(params_type[1]);
    value = read_bytes(vm, (pc + (param1 + param2) % IDX_MOD) % MEM_SIZE,
        REG_SIZE);
    write_value_in_reg(vm, proc, offset, value);
    offset += compute_offset_specials(params_type[2]);
    proc->carry = (param1 + param2 == 0) ? 1 : 0;
    proc->pc = (pc + offset) % MEM_SIZE;
    return;
}
