/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** get_param_value
*/

#include "my.h"

int compute_offset_specials(char type)
{
    switch (type) {
        case 3:
            return 2;
        case 2:
            return 2;
        case 1:
            return 1;
    }
}

int compute_offset(char type)
{
    switch (type) {
        case 3:
            return 2;
        case 2:
            return 4;
        case 1:
            return 1;
    }
}

static int manage_registers(vm_t *vm, process_t *proc, char type, int offset)
{
    int reg_number = vm->mem[(proc->pc + offset) % MEM_SIZE];
    int value = proc->reg[reg_number - 1];

    return value;
}

static int manage_directs(vm_t *vm, process_t *proc, char type, int offset)
{
    int value = 0;
    int opcode = proc->opcode;
    int dir_size = 0;

    if (opcode == 9 || opcode == 10 || opcode == 11 ||
        opcode == 12 || opcode == 14 || opcode == 15)
        dir_size = 2;
    value = read_bytes(vm, (proc->pc + offset) % MEM_SIZE, dir_size);
    if (dir_size == 2 && (value & 0x8000))
        value |= 0xFFFF0000;
    return value;
}

static int manage_indirects(vm_t *vm, process_t *proc, char type, int offset)
{
    int ind_adress = read_bytes(vm, (proc->pc + offset) % MEM_SIZE, IND_SIZE);
    int ind_realadress = (proc->pc + (ind_adress % IDX_MOD)) % MEM_SIZE;
    int value = read_bytes(vm, ind_realadress, IND_SIZE);

    return value;
}

int get_param_value(vm_t *vm, process_t *proc, char type, int offset)
{
    int value = 0;

    switch (type) {
        case 3:
            value = manage_indirects(vm, proc, type, offset);
            break;
        case 2:
            value = manage_directs(vm, proc, type, offset);
            break;
        case 1:
            value = manage_registers(vm, proc, type, offset);
            break;
    }
    return value;
}
