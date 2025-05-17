/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** get_param_adress
*/

#include "my.h"

void write_value_in_reg(vm_t *vm, process_t *proc, int offset, int value)
{
    int reg_nb = vm->mem[(proc->pc + offset) % MEM_SIZE];

    if (reg_nb < 1 || reg_nb > REG_NUMBER)
        return;
    proc->reg[reg_nb - 1] = value;
}

void write_value_to_ind_addr(vm_t *vm, process_t *proc, int offset, int value)
{
    int ind_adress = read_bytes(vm, (proc->pc + offset) % MEM_SIZE, IND_SIZE);
    int ind_realadress = (proc->pc + (ind_adress % IDX_MOD)) % MEM_SIZE;

    write_bytes(vm, ind_realadress, value, IND_SIZE);
}
