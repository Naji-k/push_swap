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

NAME = push_swap.a

AR = ar
CC = cc

FLAGS = -Wall -Wextra -Werror

Make = make

SRC = doubly_linked_list.c \
	main.c \
	p_s_actions.c \
	
OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}:	${OBJS}
	cd ../printf && $(MAKE)
	cp ../printf/libftprintf.a $(NAME)
	$(AR) -crs ${NAME} ${OBJS}

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS);
	cd ../printf && $(MAKE) clean

fclean: clean
	rm f $(NAME) a.out
	cd ../printf && $(MAKE) fclean

re: fclean all