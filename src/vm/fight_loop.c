/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** fight_loop
*/

#include "my.h"

static instruction_t *init_instructs(instruction_t instructions[17])
{
    for (int i = 0; i < 17; i++)
        instructions[i] = NULL;
    instructions[1] = exec_live;
    instructions[2] = exec_ld;
    instructions[3] = exec_st;
    instructions[4] = exec_add;
    instructions[5] = exec_sub;
    instructions[6] = exec_and;
    instructions[7] = exec_or;
    instructions[8] = exec_xor;
    instructions[9] = exec_zjmp;
    instructions[10] = exec_ldi;
    instructions[11] = exec_sti;
    instructions[12] = exec_fork;
    instructions[13] = exec_lld;
    instructions[14] = exec_lldi;
    instructions[15] = exec_lfork;
    instructions[16] = exec_aff;
}

static int check_if_ready(vm_t *vm, process_t *proc, int opcode)
{
    static int op_cycles[17] = {
        0, 10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2
    };

    if (proc->cooldown == -1) {
        if (opcode >= 1 && opcode <= 16)
            proc->cooldown = vm->cycles + op_cycles[opcode];
        return 1;
    }
    return 0;
}

int check_live_cycle(vm_t *vm)
{
    if (vm->nb_live >= NBR_LIVE) {
        vm->nb_live = 0;
        vm->cycle_to_die -= CYCLE_DELTA;
    }
    if (vm->cycles - vm->last_check_cycle >= vm->cycle_to_die) {
        vm->last_check_cycle = vm->cycles;
        return 1;
    }
    return 0;
}

int exec_instructs(vm_t *vm, process_t *proc)
{
    instruction_t instructs[17];
    int opcode = vm->mem[proc->pc % MEM_SIZE];

    proc->opcode = vm->mem[proc->pc % MEM_SIZE];
    init_instructs(instructs);
    if (check_if_ready(vm, proc, opcode))
        return 0;
    if (vm->cycles >= proc->cooldown) {
        if (opcode >= 1 && opcode <= 16 && instructs[opcode]) {
            instructs[opcode](vm, proc);
        }
        proc->cooldown = -1;
    }
    return 0;
}

int check_loop(vm_t *vm, process_t *tmp)
{
    if (check_live_cycle(vm)) {
        if (kill_dead_procs(vm, &vm->proc))
            return 1;
    }
    return exec_instructs(vm, tmp);
}

int process_loop(vm_t *vm, process_t *tmp)
{
    while (tmp) {
        if (check_loop(vm, tmp))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int fight_loop(vm_t *vm)
{
    process_t *tmp = vm->proc;

    vm->nb_live = 0;
    vm->cycles = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    while (vm->proc) {
        if (vm->dump_flag && vm->dump_cycles == vm->cycles)
            return dump_cycles(vm);
        if (process_loop(vm, tmp))
            break;
        vm->cycles++;
        tmp = vm->proc;
    }
    return 0;
}
