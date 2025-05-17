/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** free_array
*/

#include "../../include/my.h"

int free_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        free(array[i]);
    }
    return 0;
}
