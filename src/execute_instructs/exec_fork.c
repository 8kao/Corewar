/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_fork
*/

#include "my.h"

void exec_fork(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    char *params_type = get_params_type(vm, pc);
    int param1 = 0;
    process_t *new = malloc(sizeof(process_t));

    param1 = get_param_value(vm, proc, params_type[0], 1);
    new->carry = proc->carry;
    new->last_live = proc->last_live;
    new->owner_id = proc->owner_id;
    new->owner_name = my_strdup(proc->owner_name);
    new->cooldown = vm->cycles;
    new->opcode = proc->opcode;
    new->dead = proc->dead;
    for (int i = 0; i < REG_NUMBER; i++) {
        new->reg[i] = proc->reg[i];
    }
    new->pc = ((pc + param1) % IDX_MOD) % MEM_SIZE;
    new->next = vm->proc;
    vm->proc = new;
    proc->pc = (pc + 3) % MEM_SIZE;
}
