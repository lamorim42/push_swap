/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:30:10 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/12 12:26:45 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_new_elem(int i)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->nbr = i;
	node->next = NULL;
	return (node);
}

void	ft_push_front(t_lst **head, int i)
{
	t_lst	*new;

	new = ft_new_elem(i);
	new->next = *head;
	*head = new;
}

void	ft_push_back(t_lst **head, int i)
{
	t_lst	*new;
	t_lst	*temp;

	new = ft_new_elem(i);
	if (!*head)
		*head = new;
	else
	{
		temp = ft_last_lst(*head);
		temp->next = new;
	}
}

t_lst	*ft_last_lst(t_lst *head)
{
	t_lst	*last;

	last = head;
	while (last->next)
		last = last->next;
	return (last);
}

int	ft_is_empty(t_lst *lst)
{
	if (!lst)
		return (1);
	return (0);
}
