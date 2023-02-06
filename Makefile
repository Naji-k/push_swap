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


CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = ./libft/libft.a
Make = make

SRC = circular_doubly_linked_list.c \
	main.c \
	p_s_actions.c \
	push_swap.c \
	sort_big_num.c \
	parsing_inputs.c \
	sort_numbers.c \

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}:	${OBJS}
	cd ./libft && $(MAKE) bonus
	$(CC) -o ${NAME} ${OBJS} $(LIB)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS);
	cd ../printf && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && $(MAKE) fclean

re: fclean all