/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:47:20 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/12 12:51:42 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_put_norm(t_lst **head)
{
	t_lst	*temp;
	int		i;

	if (!*head)
		return ;
	i = 0;
	temp = *head;
	while (temp)
	{
		temp->norm = i;
		temp = temp->next;
		i++;
	}
}

void	ft_normalize(t_lst **a)
{
	t_lst	*norm;
	t_lst	*temp;
	t_lst	*ptr_a;

	norm = ft_cpy_lst(a);
	bubble_sort(&norm);
	ft_put_norm(&norm);
	temp = norm;
	while (temp)
	{
		ptr_a = *a;
		while (ptr_a)
		{
			if (ptr_a->nbr == temp->nbr)
				ptr_a->norm = temp->norm;
			ptr_a = ptr_a->next;
		}
		temp = temp->next;
	}
	ft_clean_lst(&norm);
}
