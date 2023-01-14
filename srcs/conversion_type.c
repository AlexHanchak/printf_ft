/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:28:37 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 16:54:41 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

char	*conversion_type(va_list ap, t_format *f)
{
	char	*str;

	if (f->type == 'c')
		str = conversion_c(va_arg(ap, int));
	else if (f->type == 's')
		str = conversion_s(va_arg(ap, char *));
	else if (f->type == 'p')
		str = conversion_p((unsigned long long) va_arg(ap, void *));
	else if (f->type == 'i' || f->type == 'd')
		str = conversion_d(va_arg(ap, int));
	else if (f->type == 'u')
		str = conversion_u(va_arg(ap, int));
	else if (f->type == 'x')
		str = conversion_x(va_arg(ap, unsigned int), 0);
	else if (f->type == 'X')
		str = conversion_x(va_arg(ap, unsigned int), 1);
	else if (f->type == '%')
		str = conversion_c('%');
	else
		str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	return (str);
}
