/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF
    #define MY_PRINTF

    #include "my.h"
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stdio.h>

int my_printf(const char *str, ...);
void flag_c(va_list args, int *pntr);
void flag_d(va_list args, int *pntr);
void flag_e_up(va_list args, int *pntr);
void flag_e(va_list args, int *pntr);
void flag_i(va_list args, int *pntr);
void flag_o(va_list args, int *pntr);
void flag_prct(va_list args, int *pntr);
void flag_s(va_list args, int *pntr);
void flag_u(va_list args, int *pntr);
void flag_x_up(va_list args, int *pntr);
void flag_x(va_list args, int *pntr);
void flag_f(va_list args, int *pntr);
void flag_f_up(va_list args, int *pntr);
void flag_p(va_list args, int *pntr);
void flag_n(va_list args, int *pntr);
void flag_ld(va_list args, int *pntr);
void flag_lld(va_list args, int *pntr);
void flag_hd(va_list args, int *pntr);
void flag_lli(va_list args, int *pntr);
void flag_li(va_list args, int *pntr);
void flag_hi(va_list args, int *pntr);
void flag_lo(va_list args, int *pntr);
void flag_llo(va_list args, int *pntr);
void flag_ho(va_list args, int *pntr);
void flag_lu(va_list args, int *pntr);
void flag_llu(va_list args, int *pntr);
void flag_hu(va_list args, int *pntr);
void flag_lx(va_list args, int *pntr);
void flag_llx(va_list args, int *pntr);
void flag_hx(va_list args, int *pntr);
void flag_lx_up(va_list args, int *pntr);
void flag_llx_up(va_list args, int *pntr);
void flag_hx_up(va_list args, int *pntr);

#endif
