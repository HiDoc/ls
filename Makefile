# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmadura <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:12:15 by fmadura           #+#    #+#              #
#    Updated: 2018/07/18 19:34:02 by fmadura          ###   ########.fr        #
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
		   struct_env.c \
		   struct_dir.c \
		   struct_obj.c \
		   print.c \
		   utils_dir.c \
		   utils_obj.c \
		   utils_env.c \
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

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir ./objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

fsan: $(OBJ)
	@$(CC) $(CFLAGS) -g -fsanitize=address $(OBJ) $(LIB) $(INC) -o $(NAME)

lldb:
	@$(CC) $(CFLAGS) -g  $(SRC) $(LIB) $(INC) -o $(NAME)

re: fclean all
