/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:30:10 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/08 00:10:04 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_new_node(int i)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	if (!node)
		return NULL;
	node->nbr = i;
	node->next = NULL;
	return (node);
}

void	ft_push_front(t_lst **head, int i)
{
	t_lst	*new;

	new = ft_new_node(i);
	new->next = *head;
	*head = new;
}

void	ft_push_back(t_lst **head, t_lst *new)
{
	t_lst	*temp;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_clean_list(t_lst **head)
{
	t_lst	*list;
	t_lst	*temp;

	list = *head;
	while (list->next)
	{
		temp = list->next;
		list->next = temp->next;
		free(temp);
		temp = NULL;
	}
	free(list);
	list = NULL;
}