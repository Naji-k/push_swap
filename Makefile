# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nakanoun <nakanoun@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/18 12:59:01 by nakanoun      #+#    #+#                  #
#    Updated: 2023/01/18 12:59:01 by nakanoun      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

INCLUDE = -Iinclude -Ilibft/include -Iget_next_line/include

FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
GNL_DIR = ./get_next_line

LIB = $(LIBFT_DIR)/libft.a
LIB_BONUS = $(GNL_DIR)/get_next_line.a


FILES = circular_doubly_linked_list.c \
	p_s_actions_support.c \
	p_s_actions.c \
	p_s_rotate_actions.c \
	p_s_multi_actions.c \
	push_swap.c \
	sort_numbers.c \
	sort_small_numbers.c \
	sort_big_num_a2b.c \
	parsing_inputs.c \
	p_s_algorithms.c \
	p_s_b2a.c \

BONUS_FILES = src/checker.c
SOLVER = src/main.c
SRC = $(addprefix src/, $(FILES))

OBJS = ${SRC:.c=.o}
OBJS_SOLVER = ${SOLVER:.c=.o}
OBJS_BONUS = ${BONUS_FILES:.c=.o}

all:	$(NAME) bonus

$(NAME):	lib $(OBJS) $(OBJS_SOLVER)
	@$(CC) $(OBJS) $(OBJS_SOLVER) $(INCLUDE) $(LIB) -o $@

bonus: 	lib gnl ${OBJS} $(OBJS_BONUS)
		@$(CC) $(FLAGS) ${OBJS} $(OBJS_BONUS) $(INCLUDE) $(LIB) $(LIB_BONUS) -o $(BONUS)

%.o: %.c
	$(CC) -c $(FLAGS) $(INCLUDE) $< -o $@

lib:
	@make -sC $(LIBFT_DIR)

gnl:
	@make -sC$(GNL_DIR)


clean:
	rm -f $(OBJS) $(OBJS_BONUS) ${OBJS_SOLVER};
	# rm $(LIB) $(LIB_BONUS);
	@make clean -C $(GNL_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS);
	@make fclean -C $(GNL_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
.PHONY: all lib gnl clean fclean re