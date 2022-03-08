# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 21:58:08 by lamorim           #+#    #+#              #
#    Updated: 2022/03/07 23:13:55 by lamorim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME	= push_swap

#Compile configurations
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g

INCLUDE	= ./include/

SRC		= push_swap.c \

OBJ_FILES= $(SRC:.c=.o)
OBJ		= $(addprefix ./obj/, $(OBJ_FILES))

LIB		= ./library/ft_printf/
INC_LIB= ./library/ft_printf/include/
INC_LIBFT= ./library/ft_printf/libft/include/
#Remove options
RM		= rm -f

#Paths
VPATH	= ./src/

#Default goal
.DEFAULT_GOAL= all

#Git configurations
SEP ="\n\e[0;36m--------------------------------------------------------\e[0m\n"
ADD	= .
MSG	= Update

./obj/%.o: %.c
			$(CC) $(CFLAGS) -I $(INCLUDE) -I $(INC_LIB) -I $(INC_LIBFT) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -I $(INCLUDE) -I $(INC_LIB) -I $(INC_LIBFT) -L $(LIB) -lftprintf -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIB)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIB)

re: fclean all

git: fclean
	git status
	@echo $(SEP)
	git add $(ADD)
	@echo $(SEP)
	git commit -m "$(MSG)"
	@echo $(SEP)
	git status

.PHONY= all clean fclean re $(NAME)