/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:41:25 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/11 10:53:41 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_parameter(t_printf *data, const char **fmt);
static void	ft_char_helper(t_printf *data, const char **fmt);

int	ft_dprintf(int fd, const char *fmt, ...)
{
	t_printf	data;

	data.result = 0;
	va_start(data.ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			check_parameter(&data, &fmt);
			fmt++;
		}
		else
			ft_char_helper(&data, &fmt);
	}
	if (data.result == 0)
		return (0);
	ft_create_buffer(&data);
	write(fd, data.buffer, data.result);
	ft_clean_list(&data.string);
	free(data.buffer);
	return (data.result);
}

static void	check_parameter(t_printf *data, const char **fmt)
{
	if (**fmt == 'c')
		ft_putchar_inlst(data, va_arg(data->ap, int));
	else if (**fmt == 's')
		ft_putstr_inlst(data, va_arg(data->ap, char *));
	else if (**fmt == 'd' || **fmt == 'i')
		ft_putint_inlst(data, va_arg(data->ap, int));
	else if (**fmt == 'u')
		ft_putuint_inlst(data, va_arg(data->ap, unsigned int));
	else if (**fmt == 'x')
		ft_itoa_put_inlst(data, 0);
	else if (**fmt == 'X')
		ft_itoa_put_inlst(data, 1);
	else if (**fmt == 'p')
		ft_itoa_address(data);
	else if (**fmt == '%')
		ft_putchar_inlst(data, '%');
	else
		ft_putchar_inlst(data, **fmt);
}

static void	ft_char_helper(t_printf *data, const char **fmt)
{
	t_char	*temp;

	if (data->result == 0)
		data->string = ft_new_node(**fmt);
	else
	{
		temp = ft_new_node(**fmt);
		ft_add_node(&data->string, temp);
	}
	(*fmt)++;
	data->result++;
}
