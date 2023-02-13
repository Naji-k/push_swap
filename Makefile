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

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = libft.a
LIB_BONUS = get_next_line.a
Make = make

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

all: ${NAME} $(BONUS)

${NAME}:	${OBJS} ${OBJS_SOLVER}
	cd ./libft && $(Make) bonus
	cp ./libft/libft.a .
	$(CC) $(FLAGS) ${OBJS} ${OBJS_SOLVER} $(INCLUDE) $(LIB) -o $@

$(BONUS):	${OBJS} $(OBJS_BONUS)
	# cd ./libft && $(Make) bonus
	# cp ./libft/libft.a .
	cd ./get_next_line && $(MAKE)
	cp ./get_next_line/get_next_line.a .
	$(CC) $(FLAGS) ${OBJS} $(OBJS_BONUS) $(INCLUDE) $(LIB) $(LIB_BONUS) -o $@

%.o : %.c
	$(CC) -c $(FLAGS) $(INCLUDE) $^ -o $@


clean:
	rm -f $(OBJS) $(OBJS_BONUS) ${OBJS_SOLVER};
	rm $(LIB) $(LIB_BONUS);
	cd ./libft && $(MAKE) clean
	cd ./get_next_line && $(MAKE) clean

fclean: clean
	rm -f $(NAME) $(BONUS);
	cd ./libft && $(MAKE) fclean
	cd ./get_next_line && $(MAKE) fclean

re: fclean all