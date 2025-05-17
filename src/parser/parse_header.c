/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** parse_each_file
*/

#include "my.h"

int get_prog_comment(champ_t *champ, FILE *fd)
{
    int comment_bytes = fread(champ->comment, 1, COMMENT_LENGTH, fd);

    if (!comment_bytes)
        return my_putstr_error("Error: Invalid comment.\n");
    champ->comment[COMMENT_LENGTH] = '\0';
    fseek(fd, 4, SEEK_CUR);
    return 0;
}

int get_prog_size(champ_t *champ, FILE *fd)
{
    unsigned char buf[4];

    fread(buf, 1, 4, fd);
    champ->prog_size = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8)
        | buf[3];
    if (champ->prog_size <= 0 || champ->prog_size > MEM_SIZE)
        return my_putstr_error("Error: Invalid prog_size.\n");
    return 0;
}

int get_prog_name(champ_t *champ, FILE *fd)
{
    int name_bytes = fread(champ->name, 1, PROG_NAME_LENGTH, fd);

    if (name_bytes != PROG_NAME_LENGTH)
        return my_putstr_error("Error: Invalid name.\n");
    champ->name[PROG_NAME_LENGTH] = '\0';
    fseek(fd, 4, SEEK_CUR);
    return 0;
}

static int check_magic_nb(FILE *fd)
{
    unsigned char buf[4];
    int magic_nb = 0;

    fread(buf, 1, 4, fd);
    magic_nb = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
    if (magic_nb != COREWAR_EXEC_MAGIC)
        return my_putstr_error("Error: Invalid magic number.\n");
    return 0;
}

int parse_header(champ_t *champ, FILE *fd)
{
    if (check_magic_nb(fd) || get_prog_name(champ, fd) ||
        get_prog_size(champ, fd) || get_prog_comment(champ, fd))
        return 84;
    return 0;
}

int parse_each_file(champ_t *champ, char **argv, int i)
{
    FILE *fd = fopen(argv[i], "rb");

    check_if_flags(champ, argv, i);
    if (!fd) {
        my_putstr_error("Error: Couldn't open ");
        my_putstr_error(argv[i]);
        return my_putstr_error(".\n");
    }
    if (parse_header(champ, fd) || parse_body(champ, fd))
        return 84;
    return 0;
}
