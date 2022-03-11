/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_inlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:41:41 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/11 10:56:36 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_inlst(t_printf *data, char c)
{
	t_char	*temp;

	if (data->result == 0)
		data->string = ft_new_node(c);
	else
	{
		temp = ft_new_node(c);
		ft_add_node(&data->string, temp);
	}
	data->result++;
}

void	ft_putstr_inlst(t_printf *data, char *str)
{
	int			i;
	const char	*temp;

	i = 0;
	if (!str)
	{
		temp = "(null)";
		while (temp[i])
		{
			ft_putchar_inlst(data, temp[i]);
			i++;
		}
		return ;
	}
	while (str[i])
	{
		ft_putchar_inlst(data, str[i]);
		i++;
	}
}

void	ft_putint_inlst(t_printf *data, int nbr)
{
	long int	n;
	char		*ptr;
	char		*str;
	int			signal;
	int			len;

	signal = 0;
	n = nbr;
	if (n < 0)
	{
		signal = 1;
		n = -n;
	}
	len = ft_count_digit(n, 10);
	str = malloc(sizeof(char) * (len + 1 + signal));
	if (!str)
		return ;
	ptr = &str[len + signal];
	*ptr = '\0';
	ft_strfill(&ptr, n, signal);
	ft_putstr_inlst(data, ptr);
	free(ptr);
}

void	ft_putuint_inlst(t_printf *data, unsigned int nbr)
{
	unsigned int	n;
	char			*ptr;
	char			*str;
	int				len;

	n = nbr;
	len = ft_count_digit(n, 10);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	ptr = &str[len];
	*ptr = '\0';
	ft_strfill(&ptr, n, 0);
	ft_putstr_inlst(data, ptr);
	free(ptr);
}

void	ft_itoa_put_inlst(t_printf *data, int flag)
{
	char	*result;

	result = ft_itoa_basef(va_arg(data->ap, unsigned long int), 16, flag);
	ft_putstr_inlst(data, result);
	free(result);
}
