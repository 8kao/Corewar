/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_zjmp
*/

#include "my.h"

void exec_zjmp(vm_t *vm, process_t *proc)
{
    int pc = proc->pc;
    int index = get_param_value(vm, proc, 2, 1);
    int jump = 0;

    if (proc->carry) {
        jump = (pc + (index % IDX_MOD)) % MEM_SIZE;
        if (jump < 0)
            jump += MEM_SIZE;
        proc->pc = jump;
    } else {
        proc->pc = (pc + 3) % MEM_SIZE;
    }
}
