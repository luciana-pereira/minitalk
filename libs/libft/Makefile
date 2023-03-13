# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 18:19:23 by lucperei          #+#    #+#              #
#    Updated: 2023/02/17 00:29:07 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -I./ -c

SRC = ft_atoi.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strlcpy.c \

OBJS = $(SRC:.c=.o)

RM = rm -f

AR = ar rc

CC = gcc

$(NAME): $(OBJS) libft.h
		$(CC) $(FLAGS) $(SRC)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean: 
		$(RM) $(OBJS)
		
fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
