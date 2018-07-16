# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmadura <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:12:15 by fmadura           #+#    #+#              #
#    Updated: 2018/07/16 13:20:06 by fmadura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

#command
EOLCLR		= "\\033[0K"
#unicode
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(CYAN)$(CHECK)$(WHITE)"

NAME = ft_ls

CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/ \
		   ./libft/includes/

SRC_NAME = ft_ls.c \
		   utils_stat.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = -L ./libft/ -lftprintf

.PHONY : all clean fclean re

all: $(NAME)
	./ft_ls

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) -o $(NAME)
	$(complete)

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir ./objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	$(cleaning)

fclean: clean
	@rm -f $(NAME)
	$(cleaning)

re: fclean all
