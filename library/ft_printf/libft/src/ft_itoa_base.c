/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:13:31 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/05 21:18:19 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(long int c, int base);

char	*ft_itoa_base(unsigned int n, int base)
{
	const char			*hold_base;
	char				*ptr;
	char				*str;
	long int			n_cpy;
	int					len;

	hold_base = "0123456789abcdef";
	n_cpy = n;
	len = ft_count_digit(n_cpy, base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ptr = &str[len];
	*ptr = '\0';
	if (!n)
		*(--ptr) = hold_base[n_cpy / base];
	while (n_cpy)
	{
		*(--ptr) = hold_base[n_cpy % base];
		n_cpy /= base;
	}
	return (ptr);
}

static int	ft_count_digit(long int c, int base)
{
	int	len;

	if (!c)
		return (1);
	len = 0;
	while (c > 0)
	{
		c /= base;
		len++;
	}
	return (len);
}
