/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:41:37 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/07 23:25:39 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_node {
	char			c;
	struct s_node	*next;
}					t_node;

typedef struct s_data {
	va_list	ap;
	int		result;
	char	*buffer;
	t_node	*string;
	t_node	*head;
}			t_data;

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
void	ft_putchar_inlst(t_data *data, char c);
void	ft_putstr_inlst(t_data *data, char *str);
void	ft_putint_inlst(t_data *data, int nbr);
void	ft_putuint_inlst(t_data *data, unsigned int nbr);
void	ft_itoa_put_inlst(t_data *data, int flag);

//ft_printf_utils.c
void	ft_strfill(char **ptr, long int n, int signal);
void	ft_create_buffer(t_data *data);
char	*ft_itoa_basef(unsigned long int n, int base, int upper);
int		ft_count_digit(unsigned long int x, int base);
void	ft_itoa_address(t_data *data);

//ft_list.c
t_node	*ft_new_node(char c);
void	ft_add_node(t_node **node, t_node *new);
void	ft_clean_list(t_node **node);

#endif
