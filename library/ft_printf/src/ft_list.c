/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:41:31 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/11 10:54:00 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_char	*ft_new_node(char c)
{
	t_char	*node;

	node = malloc(sizeof(t_char));
	if (!node)
		return (NULL);
	node->c = c;
	node->next = NULL;
	return (node);
}

void	ft_add_node(t_char **node, t_char *new)
{
	t_char	*temp;

	temp = *node;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_clean_list(t_char **node)
{
	t_char	*list;
	t_char	*temp;

	list = *node;
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
