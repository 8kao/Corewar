/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "my.h"

void destroy_vm(vm_t *vm)
{
    process_t *tmp = vm->proc;
    process_t *next;

    while (tmp) {
        next = tmp->next;
        if (tmp->owner_name)
            free(tmp->owner_name);
        free(tmp);
        tmp = next;
    }
    if (vm->last_alive_name)
        free(vm->last_alive_name);
    for (int i = 0; i < vm->nb_champ; i++) {
        if (vm->champion[i].code)
            free(vm->champion[i].code);
    }
    if (vm->champion)
        free(vm->champion);
    free(vm);
}

static int is_cor_file(char *str)
{
    int len = my_strlen(str);

    if (len > 4 && my_strcmp(&str[len - 4], ".cor") == 0)
        return 1;
    return 0;
}

void init_single_champ(champ_t *champ)
{
    champ->name[0] = '\0';
    champ->comment[0] = '\0';
    champ->code = NULL;
    champ->prog_size = 0;
    champ->adress = -1;
    champ->id = -1;
}

int init_vm(int ac, vm_t *vm, char **argv)
{
    vm->proc = NULL;
    vm->nb_champ = 0;
    for (int i = 1; i < ac; i++) {
        if (is_cor_file(argv[i]))
            vm->nb_champ++;
    }
    vm->champion = malloc(sizeof(champ_t) * vm->nb_champ);
    for (int i = 0; i < vm->nb_champ; i++)
        init_single_champ(&vm->champion[i]);
    if (!vm->champion)
        return 84;
    vm->last_alive_id = 0;
    vm->last_alive_name = NULL;
    vm->last_check_cycle = 0;
    vm->dump_cycles = -1;
    vm->dump_flag = -1;
    return 0;
}

int parse_champions(int ac, char **argv, vm_t *vm)
{
    int j = 0;

    if (init_vm(ac, vm, argv))
        return 84;
    if (vm->nb_champ <= 1)
        return my_putstr_error("Error: Too few champions\n");
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(argv[i], "-dump") == 0) {
            manage_dump_flag(vm, argv[i + 1]);
            i += 2;
        }
        if (!is_cor_file(argv[i])) {
            i += 2;
        }
        if (parse_each_file(&vm->champion[j], argv, i))
            return 84;
        j++;
    }
    return 0;
}

int main(int ac, char **argv)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (argv[1] && my_strcmp(argv[1], "-h") == 0)
        return usage_explanations();
    if (!vm || parse_champions(ac, argv, vm) || load_vm(vm))
        return 84;
    fight_loop(vm);
    destroy_vm(vm);
    return 0;
}
