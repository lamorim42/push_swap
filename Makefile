# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 21:58:08 by lamorim           #+#    #+#              #
#    Updated: 2022/03/13 13:08:00 by lamorim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME	= push_swap

#Compile configurations
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g

INCLUDE	= ./include/

SRC_L	=	list.c \
			list_utils.c \

SRC_R	=	swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \

SRC_S	=	stack.c

SRC		=	$(SRC_L) \
			$(SRC_R) \
			$(SRC_S) \
			push_swap.c \
			ft_long_atoi.c \
			bubble_sort.c \
			normalize.c \
			small_sort.c \

OBJ_FILES= $(SRC:.c=.o)
OBJ		= $(addprefix ./obj/, $(OBJ_FILES))

LIB		= ./library/ft_printf/
INC_LIB= ./library/ft_printf/include/
INC_LIBFT= ./library/ft_printf/libft/include/

INCLUDES= -I $(INCLUDE) -I $(INC_LIB) -I $(INC_LIBFT)
#Remove options
RM		= rm -f

#Paths
VPATH	= ./src/ ./rules/ ./list/ ./stack/

#Default goal
.DEFAULT_GOAL= all

#Git configurations
SEP ="\n\e[0;36m--------------------------------------------------------\e[0m\n"
ADD	= .
MSG	= Update

./obj/%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -L $(LIB) -lftprintf -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIB)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIB)

re: fclean all

run:
	./push_swap 7 6 3 4 5 2 1

runv:
	valgrind -s --leak-check=full ./push_swap 7 6 3 4 5 2 1

git: fclean
	git status
	@echo $(SEP)
	git add $(ADD)
	@echo $(SEP)
	git commit
	@echo $(SEP)
	git status

.PHONY= all clean fclean re $(NAME)