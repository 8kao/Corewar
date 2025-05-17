/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_lld
*/

#include "my.h"

void exec_lld2(vm_t *vm, process_t *proc, int param1, int offset)
{
    int reg_nb = 0;

    reg_nb = vm->mem[(proc->pc + offset) % MEM_SIZE];
    proc->reg[reg_nb - 1] = param1;
}

void exec_lld(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int offset = 2;
    char *params_type = get_params_type(vm, pc);
    int param1 = 0;
    int ind_realadress = 0;
    int ind_adress = 0;

    if (params_type[0] == 2) {
        param1 = get_param_value(vm, proc, params_type[0], offset);
    } else {
        ind_adress = read_bytes(vm, (proc->pc + offset) % MEM_SIZE, IND_SIZE);
        ind_realadress = (proc->pc + ind_adress) % MEM_SIZE;
        param1 = read_bytes(vm, ind_realadress, IND_SIZE);
    }
    offset += compute_offset(params_type[0]);
    exec_lld2(vm, proc, param1, offset);
    offset += 1;
    proc->carry = (param1 == 0) ? 1 : 0;
    proc->pc = (pc + offset) % MEM_SIZE;
    return;
}
