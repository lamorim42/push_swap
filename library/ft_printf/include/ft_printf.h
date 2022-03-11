/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:41:37 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/11 10:53:24 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_node {
	char			c;
	struct s_node	*next;
}					t_char;

typedef struct s_data {
	va_list	ap;
	int		result;
	char	*buffer;
	t_char	*string;
	t_char	*head;
}			t_printf;

typedef struct s_itoa {
	unsigned long int	n_cpy;
	const char			*hold_base;
	char				*ptr;
	char				*str;
	int					len;
}						t_itoa;

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);

//ft_put_inlst.c
void	ft_putchar_inlst(t_printf *data, char c);
void	ft_putstr_inlst(t_printf *data, char *str);
void	ft_putint_inlst(t_printf *data, int nbr);
void	ft_putuint_inlst(t_printf *data, unsigned int nbr);
void	ft_itoa_put_inlst(t_printf *data, int flag);

//ft_printf_utils.c
void	ft_strfill(char **ptr, long int n, int signal);
void	ft_create_buffer(t_printf *data);
char	*ft_itoa_basef(unsigned long int n, int base, int upper);
int		ft_count_digit(unsigned long int x, int base);
void	ft_itoa_address(t_printf *data);

//ft_list.c
t_char	*ft_new_node(char c);
void	ft_add_node(t_char **node, t_char *new);
void	ft_clean_list(t_char **node);

#endif
