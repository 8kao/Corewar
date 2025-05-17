##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## lib's makefile
##


SRC 	=	my_putchar.c	\
		my_put_nbr.c 	\
		my_putstr.c 	\
		my_atoi.c		\
		my_getnbr.c 	\
		my_strcmp.c 	\
		my_str_to_word_array.c	\
		my_isalnum.c 	\
		my_strcat.c 	\
		my_strlen.c 	\
		my_strcspn.c	\
		my_strcpy.c 	\
		free_array.c 	\
		my_strdup.c 	\
		my_isnumber.c 	\
		my_arraylen.c 	\
		my_put_nbr_base.c \
		my_strncpy.c 		\
		libprintf/flag_c.c \
		libprintf/flag_d.c \
		libprintf/flag_e.c \
		libprintf/flag_e_up.c \
		libprintf/flag_f.c \
		libprintf/flag_f_up.c \
		libprintf/flag_hd.c \
		libprintf/flag_hi.c \
		libprintf/flag_ho.c \
		libprintf/flag_hu.c \
		libprintf/flag_hx.c \
		libprintf/flag_hx_up.c \
		libprintf/flag_i.c \
		libprintf/flag_ld.c \
		libprintf/flag_li.c \
		libprintf/flag_lld.c \
		libprintf/flag_lli.c \
		libprintf/flag_llo.c \
		libprintf/flag_llu.c \
		libprintf/flag_llx.c \
		libprintf/flag_llx_up.c \
		libprintf/flag_lo.c \
		libprintf/flag_lu.c \
		libprintf/flag_lx.c \
		libprintf/flag_lx_up.c \
		libprintf/flag_n.c \
		libprintf/flag_o.c \
		libprintf/flag_p.c \
		libprintf/flag_prct.c \
		libprintf/flag_s.c \
		libprintf/flag_u.c \
		libprintf/flag_x.c \
		libprintf/flag_x_up.c \
		libprintf/my_printf.c \

OBJ	= 	$(SRC:.c=.o)

NAME 	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:     fclean all
