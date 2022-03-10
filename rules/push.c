/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:04:17 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/10 18:45:14 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_lst **from, t_lst **to, const char stk)
{
	if (!*from)
		return ;
	if (!*to)
	{
		(*to) = ft_new_elem((*from)->nbr);
		ft_delone(from);
	}
	else
	{
		ft_push_front(to, (*from)->nbr);
		ft_delone(from);
	}
	ft_printf("p%c\n", stk);
}
