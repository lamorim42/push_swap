/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:17:19 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/12 12:54:15 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_lst	*ft_cpy_lst(t_lst **head)
{
	t_lst	*temp;
	t_lst	*cpy;

	if (!*head)
		return (NULL);
	temp = *head;
	cpy = ft_new_elem(temp->nbr);
	temp = temp->next;
	while (temp)
	{
		ft_push_back(&cpy, temp->nbr);
		temp = temp->next;
	}
	return (cpy);
}

int	ft_is_sorted(t_lst **list)
{
	int		flag;
	t_lst	*temp;

	flag = 0;
	temp = *list;
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			flag = 1;
		else if (flag == 1)
			break ;
		temp = temp->next;
	}
	return (flag);
}
