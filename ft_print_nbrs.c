/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:22:49 by ohanchak          #+#    #+#             */
/*   Updated: 2022/12/27 16:17:17 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static char	*ft_allocate(char *str, int len, unsigned int n, unsigned int n_bak)
{
	if (n_bak == 0)
		len = 1;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	n_bak;

	n_bak = n;
	len = ft_nbrlen(n, 10);
	str = NULL;
	str = ft_allocate(str, len, n, n_bak);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	plus(t_format f)
{
	if (f.plus)
		return ('+');
	return ('-');
}

static int	ft_print_nbr(t_format f, char *nbr, int len, int neg)
{
	int	c;

	c = 0;
	f.width -= (f.space && !neg && !f.plus && f.width);
	if (neg || f.plus)
		c += ft_putnchar_fd(plus(f), 1, f.zero && (!f.dot || f.neg_prec));
	else if (f.space)
		c += ft_putnchar_fd(' ', 1, f.zero && !f.dot);
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		c += ft_putnchar_fd('0', 1, f.width - f.precision - neg - f.plus);
	else if (!f.minus && f.width > f.precision)
		c += ft_putnchar_fd(' ', 1, f.width - f.precision - neg - f.plus);
	if (neg || f.plus)
		c += ft_putnchar_fd(plus(f), 1, !f.zero || (f.dot && !f.neg_prec));
	else if (f.space)
		c += ft_putnchar_fd(' ', 1, !f.zero || f.dot);
	c += ft_putnchar_fd('0', 1, f.precision - len);
	c += write(1, nbr, len);
	if (f.minus && f.width > f.precision)
		c += ft_putnchar_fd(' ', 1, f.width - f.precision - neg - f.plus);
	return (c);
}

int	ft_print_d_i_u(t_format f, va_list ap)
{
	char	*nbr;
	int		n;
	int		c;
	int		len;
	int		neg;

	c = 0;
	n = va_arg(ap, int);
	neg = (n < 0 && n != INT_MIN && f.specifier != 'u');
	if (neg)
		f.plus = 0;
	if (n < 0 && f.specifier != 'u')
		n *= -1;
	if (n < 0 && f.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.precision && f.dot)
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	c += ft_print_nbr(f, nbr, len, neg);
	free(nbr);
	return (c);
}
