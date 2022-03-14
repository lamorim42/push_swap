
# push_swap

Push_swap is a project where we have to leave data in order using two stacks and allowed operations

## How to navagate in this repository

- [`include`](./include/) - The include file `push_swap.h`;
- [`library`](./library/) - The `libftprintf.a`
in [`ft_printf`](./library/ft_printf/);
- [`list`](./list/) - The list functions;
- [`rules`](./rules/) - The rules to manipulate stakcs
- [`src`](./src/) - source code;
- [`obj`](./obj/) - object files.
- [`Makefile`](./Makefile) - Makefile to compile `push_swap`;

## How I implemented push_swap

To implement the stack structure I used linked-list as data structure.
For that I build functions to manipulate the list and I used these functions
to build the functions that manipulate the stack according to the project rules.

# The library

I used [_libftprintf_](https://github.com/lamorim42/ft_printf) to make the project. This lib is already an update
of [_libft_](https://github.com/lamorim42/libft).

# Linked-list

I used the linked-list data structure to make the stacks. For that we have some
functions to manipulate lists.

## My list

My list has the `int nbr` as content and a pointer to the address of the next list element or `NULL` if it's the last element.

```c
typedef struct s_lst {
	int				nbr;
	struct s_lst	*next;
}					t_lst;
```

## [Functions](./list/list.c)

- `t_lst	*ft_new_elem(int i)`
	- _Brief_: allocate space for a new node, where `i` is the content of
	the node.
	- _Param_: `int i` the content to the new node.
	- _Return_: a pointer to the new node.

- `void	ft_delone(t_lst **head)`
	- _Brief_: delete one element of the list, the first element.
	- _Param_: `t_lst **head` the address of the first element of the list.
	- _Return_: `void`.

- `void	ft_clean_lst(t_lst **head)`
	- _Brief_: clean the list, use `free()` to free used memory spaces.
	- _Param_: `t_lst **head` the address of the first element of the list.
	- _Return_: `void`.

- `t_lst	*ft_last_lst(t_lst *head)`
	- _Brief_: finds and return the last element of the list.
	- _Param_: `t_lst *head` a pointer to the first element of the list.
	- _Return_: a pointer to the last element of the list.

# Stack

Stack is a linear abstract data type where elements are stacked and follow
some rules for their manipulation. In this projects we have some rules
we can use [see rules](#the-rules). We use two stack `a` and `b` to organize
the data.

## My stack

My stack has a pointer to a list `t_lst	*lst`, the length of the stack
`unsigned int	len` and the name of the stack `char	stk`.

```c
typedef struct s_stack {
	char			stk;
	t_lst			*lst;
	unsigned int	len;
}					t_stack;
```

# The rules

TODO

# Source code

TODO

# TODO
