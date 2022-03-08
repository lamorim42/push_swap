/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:28:00 by lamorim           #+#    #+#             */
/*   Updated: 2021/08/18 23:34:31 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*obj;

	if (nmemb * size > 2141483647)
		return (NULL);
	obj = malloc(size * nmemb);
	if (!obj)
		return (NULL);
	ft_bzero(obj, size * nmemb);
	return (obj);
}
