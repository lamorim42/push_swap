/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:03:06 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/12 13:13:02 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_fill_stack(t_lst **head, int i);

int	ft_init_stack(t_stack *stack, char stk)
{
	if (stk != 'a' && stk != 'b')
	{
		ft_dprintf(2, "Error\nBad stack init!\n");
		return (1);
	}
	stack->stk = stk;
	stack->lst = NULL;
	stack->len = 0;
	return (0);
}

int	ft_gen_stack(t_stack *a, int arg_c, char **arg_v)
{
	while ((int)a->len + 1 < arg_c)
	{
		if (ft_can_put_in_lst(arg_v[a->len + 1]))
		{
			ft_clean_lst(&(a->lst));
			ft_dprintf(2, "Error\n");
			return (1);
		}
		if (ft_fill_stack(&(a->lst), ft_atoi(arg_v[a->len + 1])))
		{
			ft_clean_lst(&(a->lst));
			ft_dprintf(2, "Error\n");
			return (2);
		}
		a->len++;
	}
	return (0);
}

static int	ft_fill_stack(t_lst **head, int i)
{
	t_lst	*temp;

	temp = *head;
	if (!*head)
		*head = ft_new_elem(i);
	else
	{
		while (temp->next)
		{
			if (temp->nbr == i)
				return (1);
			temp = temp->next;
		}
		if (temp->nbr == i)
			return (1);
		temp->next = ft_new_elem(i);
	}
	return (0);
}
