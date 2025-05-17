/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** robot factory
*/

#ifndef MY_H_
    #define MY_H_

    #include "op/op.h"
    #include "my_printf.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <dirent.h>
    #include <ctype.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <stdbool.h>

typedef struct process_s {
    int pc;
    int reg[REG_NUMBER];
    int carry;
    int last_live;
    int owner_id;
    char *owner_name;
    int cooldown;
    int opcode;
    int dead;
    struct process_s *next;
} process_t;

typedef struct champ_s {
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    char *code;
    int adress;
    int id;
    int prog_size;
} champ_t;

typedef struct vm_s {
    int nb_champ;
    champ_t *champion;
    unsigned char mem[MEM_SIZE];
    int cycles;
    process_t *proc;
    char *last_alive_name;
    int last_alive_id;
    int nb_live;
    int dump_cycles;
    int dump_flag;
    int cycle_to_die;
    int last_check_cycle;
} vm_t;


int usage_explanations(void);

//PARSER
int parse_each_file(champ_t *champ, char **argv, int i);
int parse_body(champ_t *champ, FILE *fd);
int check_if_flags(champ_t *champ, char **argv, int i);
int manage_dump_flag(vm_t *vm, char *nb);

//VM
int load_vm(vm_t *vm);
void my_memcpy(void *dest, const void *src, size_t size);
int fight_loop(vm_t *vm);
int kill_dead_procs(vm_t *vm, process_t **head);
int dump_cycles(vm_t *vm);
void dump_mem(vm_t *vm);
char *get_params_type(vm_t *vm, int pc);
int read_bytes(vm_t *vm, int addr, int size);
void write_bytes(vm_t *vm, int address, int value, int size);
int get_param_value(vm_t *vm, process_t *proc, char type, int offset);
void write_value_to_ind_addr(vm_t *vm, process_t *proc, int offset, int value);
void write_value_in_reg(vm_t *vm, process_t *proc, int offset, int value);
int compute_offset(char type);
int compute_offset_specials(char type);
int count_different_players(vm_t *vm);

//FUNCTION FOR EACH INSTRUCTION
typedef void (*instruction_t)(vm_t *vm, process_t *proc);
void exec_live(vm_t *vm, process_t *proc);
void exec_ld(vm_t *vm, process_t *proc);
void exec_st(vm_t *vm, process_t *proc);
void exec_add(vm_t *vm, process_t *proc);
void exec_sub(vm_t *vm, process_t *proc);
void exec_and(vm_t *vm, process_t *proc);
void exec_or(vm_t *vm, process_t *proc);
void exec_xor(vm_t *vm, process_t *proc);
void exec_zjmp(vm_t *vm, process_t *proc);
void exec_ldi(vm_t *vm, process_t *proc);
void exec_sti(vm_t *vm, process_t *proc);
void exec_fork(vm_t *vm, process_t *proc);
void exec_lld(vm_t *vm, process_t *proc);
void exec_lldi(vm_t *vm, process_t *proc);
void exec_lfork(vm_t *vm, process_t *proc);
void exec_aff(vm_t *vm, process_t *proc);



//LIB
int my_atoi(char *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(const char *str, const char *reject);
int my_isalnum(char c);
char *my_strcat(char *str, char *addstr);
int my_strlen(char const *str);
size_t my_strcspn(const char *str, const char *reject);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *str);
int my_isnumber(char *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_arraylen(char **array);
int free_array(char **array);
int my_putstr_error(char *str);
char *my_strncpy(char const *src, int n);
int my_put_nbr_base(unsigned int nbr, char const *base);

#endif /* MY_H_ */
