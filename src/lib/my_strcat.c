/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(char *str, char *addstr)
{
    int len = my_strlen(str);
    int addlen = my_strlen(addstr);
    char *newstr = malloc(sizeof(char) * (len + addlen + 1));

    for (int i = 0; i < len; i++)
        newstr[i] = str[i];
    for (int i = 0; i < addlen; i++)
        newstr[len + i] = addstr[i];
    newstr[len + addlen] = '\0';
    return newstr;
}
