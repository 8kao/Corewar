/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** load_vm
*/

#include "my.h"

int find_smallest_id(vm_t *vm, int id)
{
    for (int i = 0; i < vm->nb_champ; i++) {
        if (vm->champion[i].id == id)
            return 1;
    }
    return 0;
}

int find_smallest_id_loop(vm_t *vm)
{
    int taken = 0;

    for (int id = 1; id <= 6; id++) {
        if (!find_smallest_id(vm, id))
            return id;
    }
}

void init_process(process_t *proc, champ_t *champ)
{
    proc->pc = champ->adress;
    for (int i = 0; i < REG_NUMBER; i++) {
        proc->reg[i] = 0;
    }
    proc->reg[0] = champ->id;
    proc->carry = 0;
    proc->cooldown = -1;
    proc->last_live = 0;
    proc->dead = 0;
    proc->next = NULL;
}

int create_process(vm_t *vm)
{
    process_t *new = NULL;

    for (int i = 0; i < vm->nb_champ; i++) {
        new = malloc(sizeof(process_t));
        if (!new)
            return 84;
        init_process(new, &vm->champion[i]);
        new->owner_id = vm->champion[i].id;
        new->owner_name = my_strdup(vm->champion[i].name);
        new->next = vm->proc;
        vm->proc = new;
    }
    return 0;
}

int load_vm(vm_t *vm)
{
    int addr = 0;

    for (int i = 0; i < MEM_SIZE; i++)
        vm->mem[i] = '\0';
    for (int i = 0; i < vm->nb_champ; i++) {
        if (vm->champion[i].adress == -1)
            addr = i * (MEM_SIZE / vm->nb_champ);
        else
            addr = vm->champion[i].adress;
        if (addr + vm->champion[i].prog_size > MEM_SIZE)
            return my_putstr_error("Error: Prog size is bigger than memory\n");
        vm->champion[i].adress = addr;
        if (vm->champion[i].id == -1)
            vm->champion[i].id = find_smallest_id_loop(vm);
        my_memcpy(&vm->mem[addr], vm->champion[i].code,
            vm->champion[i].prog_size);
    }
    vm->mem[MEM_SIZE] = '\0';
    return create_process(vm);
}
