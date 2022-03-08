# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 14:46:45 by lamorim           #+#    #+#              #
#    Updated: 2022/03/07 22:40:47 by lamorim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME =	libftprintf.a

#Lib compile options
CCLIB =	ar rcs
LIB =	./libft/

#Compile options
CC =	clang
CFLAGS =	-Wall -Werror -Wextra -g

INCLUDE =	./include/
INCLUDELIB =	./libft/include/

SRC =	ft_printf.c \
		ft_dprintf.c \
		ft_list.c \
		ft_put_inlst.c \
		ft_printf_utils.c \

OBJ =	$(SRC:.c=.o)
OBJ_DIR = $(addprefix obj/, $(OBJ))

#Remove options
RM =	rm -f

#Paths to search
VPATH = src

# Default goal
.DEFAULT_GOAL	= all

#Git configurations
SEP ="\n\e[0;36m--------------------------------------------------------\e[0m\n"
ADD	= .
MSG	= Update

#Rules
obj/%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(INCLUDELIB) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ_DIR)
	make -C $(LIB)
	cp $(LIB)/libft.a $(NAME)
	$(CCLIB) $(NAME) $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIB)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIB)

re:	fclean all

git:		fclean
			git status
			@echo $(SEP)
			git add $(ADD)
			@echo $(SEP)
			git commit -m "$(MSG)"
			@echo $(SEP)
			git status

.PHONY= all clean fclean re
