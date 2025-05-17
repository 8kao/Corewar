/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_sti
*/

#include "my.h"

void exec_sti(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int offset = 2;
    char *params_type = get_params_type(vm, pc);
    int reg_value = 0;
    int param2 = 0;
    int param3 = 0;

    reg_value = get_param_value(vm, proc, params_type[0], offset);
    offset += compute_offset_specials(params_type[0]);
    param2 = get_param_value(vm, proc, params_type[1], offset);
    offset += compute_offset_specials(params_type[1]);
    param3 = get_param_value(vm, proc, params_type[2], offset);
    offset += compute_offset_specials(params_type[2]);
    vm->mem[(pc + (param2 + param3) % IDX_MOD) % MEM_SIZE] = reg_value;
    proc->carry = (param2 + param3 == 0) ? 1 : 0;
    proc->pc = (pc + offset) % MEM_SIZE;
    return;
}
