/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** kill_dead_procs
*/

#include "my.h"


int count_different_players_loop(vm_t *vm, process_t *tmp)
{
    int i = 0;

    for (process_t *tmp2 = vm->proc; tmp2; tmp2 = tmp2->next) {
        if (tmp != tmp2 && tmp->dead == 0 &&
            tmp->owner_id != tmp2->owner_id) {
            i++;
        }
    }
    return i;
}

int count_different_players(vm_t *vm)
{
    for (process_t *tmp = vm->proc; tmp; tmp = tmp->next)
        return count_different_players_loop(vm, tmp);
}

int kill_dead_procs(vm_t *vm, process_t **head)
{
    process_t *curr = *head;

    while (curr) {
        if ((curr->last_live <= vm->last_check_cycle)) {
            curr->dead = 1;
        }
        curr = curr->next;
    }
    if (count_different_players(vm) <= 1) {
        my_printf("The player %d(%s) has won.\n", vm->last_alive_id,
            vm->last_alive_name);
        return 1;
    }
    return 0;
}
