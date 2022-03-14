### Separator
SEP ="\n\e[0;36m--------------------------------------------------------\e[0m\n"

### Name
NAME	= libft.a

### Compilation configuration
CC		= clang
CFLAG	= -Wall -Wextra -Werror -g -I include

CCLIB	= ar rcs

SRC	=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strnstr.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcat.c \
			ft_bzero.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			get_next_line.c \

OBJ	= $(SRC:.c=.o)
OBJ_DIR	= $(addprefix obj/, $(OBJ))

VPATH	= src

### Extra configurations
RM		= rm -f

TEST	= test

LFLAG	= -L. -lft

### Git configurations
MSG = Update
ADD = .

### Default goal
.DEFAULT_GOAL	= all

### Rules
obj/%.o: %.c
			$(CC) $(CFLAG) -c $< -o $@

$(NAME):	$(OBJ_DIR)
			$(CCLIB) $(NAME) $(OBJ_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

git: fclean
	git status
	@echo $(SEP)
	git add $(ADD)
	@echo $(SEP)
	git commit -m "$(MSG)"
	@echo $(SEP)
	git status
	@echo $(SEP)
	git log | head -n 5

.PHONY:		all clean fclean re
