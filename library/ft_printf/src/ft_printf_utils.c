/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:51:34 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/06 14:06:48 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strfill(char **ptr, long int n, int signal)
{
	if (n == 0)
		*(--*ptr) = '0';
	while (n > 0)
	{
		*(--*ptr) = n % 10 + '0';
		n /= 10;
	}
	if (signal == 1)
		*(--*ptr) = '-';
}

int	ft_count_digit(unsigned long int x, int base)
{
	int	len;

	if (x == 0)
		return (1);
	len = 0;
	while (x > 0)
	{
		x /= base;
		len++;
	}
	return (len);
}

void	ft_create_buffer(t_data *data)
{
	int		i;
	t_node	*temp;

	data->buffer = malloc(sizeof(char) * data->result);
	i = 0;
	temp = data->string;
	while (temp->next != NULL)
	{
		data->buffer[i] = temp->c;
		i++;
		temp = temp->next;
	}
	data->buffer[i] = temp->c;
}

char	*ft_itoa_basef(unsigned long int n, int base, int upper)
{
	t_itoa	itoa;

	if (upper)
		itoa.hold_base = "0123456789ABCDEF";
	else
		itoa.hold_base = "0123456789abcdef";
	itoa.n_cpy = n;
	itoa.len = ft_count_digit(itoa.n_cpy, base);
	itoa.str = (char *)malloc(itoa.len + 1);
	if (!itoa.str)
		return (NULL);
	itoa.ptr = &itoa.str[itoa.len];
	*(itoa.ptr) = '\0';
	if (!n)
		*(--itoa.ptr) = itoa.hold_base[itoa.n_cpy / base];
	while (itoa.n_cpy)
	{
		*(--itoa.ptr) = itoa.hold_base[itoa.n_cpy % base];
		itoa.n_cpy /= base;
	}
	return (itoa.ptr);
}

void	ft_itoa_address(t_data *data)
{
	unsigned long	ads_cpy;
	const char		*prefix;
	char			*temp;
	char			*nbr;

	prefix = "0x";
	ads_cpy = va_arg(data->ap, unsigned long);
	temp = ft_itoa_basef(ads_cpy, 16, 0);
	nbr = ft_strjoin(prefix, temp);
	if (!ft_strncmp(nbr, "0x0", 3))
	{
		prefix = "(nil)";
		ft_putstr_inlst(data, (char *)prefix);
	}
	else
		ft_putstr_inlst(data, nbr);
	free(temp);
	free(nbr);
}
