/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:28:52 by lex               #+#    #+#             */
/*   Updated: 2023/01/09 16:03:52 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_char(char *cstr, int w)
{
	int		i;

	i = 0;
	if (w == 0)
		w = 1;
	while (i < w)
	{
		write(1, &cstr[i], 1);
		i++;
	}
	return (i);
}

int	printf_empty(char *cstr, t_format *f)
{
	int		n;

	n = 0;
	if (cstr[0] == 0 && f->width)
		n = print_char(" ", 1);
	else if (cstr[0] == 0 && f->dot && f->pcs < 0)
		n = print_char(S_EMPTY, S_EMPTY_L);
	else if (ft_strlen(cstr) > 0 && f->width > 0)
	{
		while (n++ < f->width)
			ft_putchar_fd(' ', 1);
		n--;
	}
	return (n);
}

int	print_str(char *cstr, t_format *f)
{
	int		n;

	if ((f->type == 's' && f->dot && f->pcs == 0) || (cstr[0] == 0))
		return (printf_empty(cstr, f));
	n = ft_strlen(cstr);
	if (f->width > 0 && n == 0)
		n = print_char(cstr, f->width);
	else
		ft_putstr_fd(cstr, 1);
	return (n);
}
