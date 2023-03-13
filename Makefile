# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 06:07:54 by lucperei          #+#    #+#              #
#    Updated: 2023/03/13 03:57:15 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
HEADER = ./includes/minitalk.h
HEADER_BONUS = ./includes/bonus/minitalk_bonus.h
LIBFT_DIR = ./libs/libft
PRINTF_DIR = ./libs/printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
SRC_CLIENT = src/client.c src/error.c src/utils.c
SRC_SERVER = src/server.c 
SRC_CLIENT_BONUS = src/bonus/client_bonus.c src/bonus/error_bonus.c rc/bonus/utils_bonus.c
SRC_SERVER_BONUS = src/bonus/server_bonus.c 

CC = cc
RM = rm -rf

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror -g3 -O3

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFT) $(PRINTF) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT) $(PRINTF) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT) $(PRINTF) $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) $(PRINTF) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT) $(PRINTF) $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) $(PRINTF) -o $(CLIENT_BONUS)
	
clean: 
	rm -rf $(OBJ_CLIENT)
	rm -rf $(OBJ_SERVER)
	rm -rf $(OBJ_CLIENT_BONUS)
	rm -rf $(OBJ_SERVER_BONUS)	
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	
fclean: clean 
	rm -f $(CLIENT)
	rm -f $(SERVER)
	rm -f $(CLIENT_BONUS)
	rm -f $(SERVER_BONUS)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
	
