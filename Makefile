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

LIB = ../printf/libftprintf.a
Make = make

SRC = doubly_linked_list.c \
	main.c \
	p_s_actions.c \
	push_swap.c \
	sort_big_num.c \
	parsing_inputs.c \

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}:	${OBJS}
	cd ../printf && $(MAKE)
	$(CC) -o ${NAME} ${OBJS} $(LIB)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS);
	cd ../printf && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd ../printf && $(MAKE) fclean

re: fclean all