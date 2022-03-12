/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:17:48 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/12 13:11:48 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

# define MAX_INT 2147483647

typedef struct s_lst {
	int				nbr;
	int				norm;
	struct s_lst	*next;
}					t_lst;

typedef struct s_stack {
	char			stk;
	t_lst			*lst;
	unsigned int	len;
}					t_stack;

//List functions
t_lst		*ft_new_elem(int i);
void		ft_push_front(t_lst **head, int i);
void		ft_push_back(t_lst **last, int i);
t_lst		*ft_last_lst(t_lst *head);
int			ft_is_empty(t_lst *lst);
void		ft_clean_lst(t_lst **head);
void		ft_delone(t_lst **head);
t_lst		*ft_cpy_lst(t_lst **head);
int			ft_is_sorted(t_lst **list);

//Rules
void		swap(t_lst **head, const char stk);
void		swap_bouth(t_lst **a, t_lst **b);
void		push(t_lst **from, t_lst **to, const char stk);
void		rotate(t_lst **head, const char stk);
void		rotate_bouth(t_lst **a, t_lst **b);
void		rrotate(t_lst **head, const char stk);
void		rrotate_bouth(t_lst **a, t_lst **b);

//Stack functions
int			ft_init_stack(t_stack *stack, char stk);
int			ft_gen_stack(t_stack *a, int arg_c, char **arg_v);

//Utils
long int	ft_long_atoi(const char *nptr);
void		bubble_sort(t_lst **head);
void		ft_normalize(t_lst **a);
int			ft_can_put_in_lst(char *arg_v);

#endif