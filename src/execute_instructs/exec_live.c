/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_instruction
*/

#include "my.h"

void exec_live(vm_t *vm, process_t *proc)
{
    if (!proc->owner_name)
        return;
    proc->last_live = vm->cycles;
    vm->nb_live++;
    vm->last_alive_id = proc->owner_id;
    if (vm->last_alive_name)
        free(vm->last_alive_name);
    vm->last_alive_name = my_strdup(proc->owner_name);
    my_printf("The player %d(%s) is alive.\n", proc->owner_id,
        proc->owner_name);
}
