/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:36:23 by lamorim           #+#    #+#             */
/*   Updated: 2021/08/18 23:13:06 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	int				i;

	i = -1;
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest > src)
	{
		while (n--)
			dest_cpy[n] = src_cpy[n];
		return (dest);
	}
	else
	{
		while (++i < (int)n)
			dest_cpy[i] = src_cpy[i];
	}
	return (dest);
}
