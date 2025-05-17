/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** parse_body
*/

#include "my.h"

int parse_body(champ_t *champ, FILE *fd)
{
    int instruct_bytes;

    champ->code = malloc(champ->prog_size);
    if (!champ->code)
        return 84;
    instruct_bytes = fread(champ->code, 1, champ->prog_size, fd);
    if (!instruct_bytes)
        return my_putstr_error("Error: Invalid instructions.\n");
    return 0;
}
