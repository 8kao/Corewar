##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## corewar makefile
##

GREEN          = \033[1;32m
RED            = \033[1;31m
ILC      	   = \033[3m
ORANGE         = \033[38;5;214m
RST            = \033[0m

SRC =		src/main.c 											\
			src/usage_explanations.c 							\
			src/parser/parse_header.c 							\
			src/parser/parse_body.c 							\
			src/parser/check_for_flags.c 						\
			src/vm/load_vm.c 									\
			src/vm/my_memcpy.c 									\
			src/vm/fight_loop.c 								\
			src/vm/kill_dead_procs.c 							\
			src/vm/dump_cycles.c 								\
			src/vm/read_bytes.c 								\
			src/vm/write_bytes.c 								\
			src/vm/get_params_type.c 							\
			src/vm/get_param_value.c 							\
			src/vm/write_value_to_adress.c 						\
			src/execute_instructs/exec_live.c 					\
			src/execute_instructs/exec_ld.c 					\
			src/execute_instructs/exec_st.c 					\
			src/execute_instructs/exec_add.c 					\
			src/execute_instructs/exec_sub.c 					\
			src/execute_instructs/exec_and.c 					\
			src/execute_instructs/exec_or.c 					\
			src/execute_instructs/exec_xor.c 					\
			src/execute_instructs/exec_zjmp.c 					\
			src/execute_instructs/exec_ldi.c 					\
			src/execute_instructs/exec_sti.c 					\
			src/execute_instructs/exec_fork.c 					\
			src/execute_instructs/exec_lld.c 					\
			src/execute_instructs/exec_lldi.c 					\
			src/execute_instructs/exec_lfork.c 					\
			src/execute_instructs/exec_aff.c

OBJ = $(SRC:.c=.o)

NAME =	corewar

CFLAGS = -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -s -C src/lib/
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L./src/lib/ -lmy
	@printf "$(GREEN)[✅] COMPILED: $(RST) $(ILC)$(NAME)$(RST)\n"

debug: CFLAGS+=-g
# debug: CFLAGS+=-g -Wextra -Wall
debug: re

sanitize: CFLAGS += -g -static-libasan -fsanitize=address
sanitize: re


clean:
	@rm -f $(OBJ)
	@printf "$(RED)[❌] CLEAN: $(RST) Removed $(ILC)objects$(RST)\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s fclean -C src/lib
	@printf "$(RED)[❌] FCLEAN: $(RST) Removed $(ILC)executables$(RST)\n"

re: fclean all

.SILENT:
