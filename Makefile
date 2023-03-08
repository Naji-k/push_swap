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

LIB_LIBFT = $(LIBFT_DIR)/libft.a
LIB_GNL = $(GNL_DIR)/get_next_line.a
CC = cc


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

OBJS = $(SRC:.c=.o)
OBJS_SOLVER =	$(OBJS) \
				$(SOLVER:.c=.o)
OBJS_BONUS = 	$(OBJS) \
				$(BONUS_FILES:.c=.o)

all:	$(NAME)

$(NAME):	$(LIB_LIBFT) $(OBJS_SOLVER)
	$(CC) $(INCLUDE) $(OBJS_SOLVER) $(LIB_LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): 	$(LIB_LIBFT) $(LIB_GNL) $(OBJS_BONUS)
		$(CC) $(FLAGS) $(INCLUDE) $(OBJS_BONUS) $(LIB_LIBFT) $(LIB_GNL) -o $(BONUS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(LIB_LIBFT):
	@make -C $(LIBFT_DIR)

$(LIB_GNL):
	@make -C $(GNL_DIR)


clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_SOLVER);
	@make clean -C $(GNL_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS);
	@make fclean -C $(GNL_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
.PHONY: all lib gnl clean fclean re