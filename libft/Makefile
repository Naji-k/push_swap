# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nakanoun <nakanoun@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/05 12:20:24 by nakanoun      #+#    #+#                  #
#    Updated: 2022/11/07 19:34:39 by nakanoun      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
CC = cc
INCLUDE = -I include

FLAG = -Wall -Wextra -Werror

FILES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c\
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c 

BONUS_FILES = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c\
			ft_lstadd_last_content.c\

SRC = $(addprefix src/, $(FILES))
BONUS = $(addprefix src/, $(BONUS_FILES))

REG_OBJS = ${SRC:.c=.o}
OBJC_BONUS = ${BONUS:.c=.o}

# ifdef WITH_BONUS
OBJS = ${REG_OBJS} ${OBJC_BONUS}
# else
# OBJS = ${REG_OBJS}
# endif

all: ${NAME}

${NAME}:	${OBJS}
	${AR} -crs ${NAME} ${OBJS}

%.o : %.c
		$(CC) -c $(FLAG) $(INCLUDE) $< -o $@

# bonus : 
# 	$(MAKE) WITH_BONUS=1 all

# for francinette
# bonus: $(NAME) $(OBJC_BONUS)
# 	$(AR) -crs $(NAME) $(OBJC_BONUS)
	
clean: 
	rm -f ${REG_OBJS} ${OBJC_BONUS}

fclean:		clean
	rm -f ${NAME} a.out libft.h.gch
	
re: fclean all