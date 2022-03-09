/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:17:48 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/08 20:39:23 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef struct s_lst {
	int				nbr;
	struct s_lst	*next;
}					t_lst;

typedef struct s_stack {
	t_lst			*top;
	t_lst			*elem;
	unsigned int	len;
}					t_stack;

//list functions
t_lst	*ft_new_elem(int i);
void	ft_push_front(t_lst **head, int i);
void	ft_push_back(t_lst **last, int i);
void	ft_clean_lst(t_lst **head);
void	swap(t_lst **head);

#endif