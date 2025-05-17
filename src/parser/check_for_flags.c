/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** check_for_flags
*/

#include "my.h"

int manage_dump_flag(vm_t *vm, char *nb)
{
    if (!nb)
        return 84;
    vm->dump_cycles = my_atoi(nb);
    vm->dump_flag = 1;
    return 0;
}

int manage_a_flag(champ_t *champ, char *nb)
{
    int address = my_atoi(nb);

    if (my_isnumber(nb) == 0)
        return my_putstr_error("Error: [-a] Invalid format\n");
    if (address < 0 || address >= MEM_SIZE)
        return my_putstr_error("Error: [-a] Invalid adress\n");
    champ->adress = address;
    return 0;
}

int manage_n_flag(champ_t *champ, char *nb)
{
    if (my_isnumber(nb) == 0)
        return my_putstr_error("Error: [-n] Invalid format\n");
    champ->id = my_atoi(nb);
    return 0;
}

int check_if_flags(champ_t *champ, char **argv, int i)
{
    if ((i - 2) < 0)
        return 0;
    if (my_strcmp(argv[i - 2], "-n") == 0) {
        return manage_n_flag(champ, argv[i - 1]);
    }
    if (my_strcmp(argv[i - 2], "-a") == 0) {
        return manage_a_flag(champ, argv[i - 1]);
    }
}
