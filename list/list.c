/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:30:10 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/09 20:48:52 by lamorim          ###   ########.fr       */
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

void	ft_push_back(t_lst **last, int i)
{
	t_lst	*new;

	new = ft_new_elem(i);
	(*last)->next = new;
	*last = new;
}

void	ft_delone(t_lst **head)
{
	t_lst	*temp;

	if (!*head)
		return ;
	temp = (*head)->next;
	(*head)->next = NULL;
	free(*head);
	*head = temp;
}

void	ft_clean_lst(t_lst **head)
{
	t_lst	*list;
	t_lst	*temp;

	if (!head)
		return ;
	list = *head;
	while (list->next != NULL)
	{
		temp = list->next;
		list->next = temp->next;
		free(temp);
		temp = NULL;
	}
	free(list);
	list = NULL;
}

//void	ft_traking_stk(t_stack *stk)
//{
//	if (!stk->lst)
//		return ;
//	stk->head = stk->lst;
//	stk->last =
//}