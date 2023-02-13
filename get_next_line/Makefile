# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nakanoun <nakanoun@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/09 14:56:33 by nakanoun      #+#    #+#                  #
#    Updated: 2023/02/09 14:56:33 by nakanoun      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

INCLUDE = -Iinclude

CC = cc

FLAGS = -Wall -Wextra -Werror

FILES = get_next_line.c \
	get_next_line_utils.c \

SRC = $(addprefix src/, $(FILES))

OBJCS = ${SRC:.c=.o}

all: $(NAME)

$(NAME):	$(OBJCS)
	ar -crs $(NAME) $(OBJCS)

%.o : %.c
		$(CC) -c $(FLAGS) $(INCLUDE) $< -o $@

clean:
	rm -f $(OBJCS)

fclean:		clean
	rm -f $(NAME)

re: fclean all