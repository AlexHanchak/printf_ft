/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:28:27 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 15:12:29 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "tools.h"

static char	*format_plus(char	*cstr, t_format *f);
static char	*format_hash(char	*cstr, t_format *f);

char	*conversion_flag(char	*cstr, t_format *f)
{
	cstr = format_plus(cstr, f);
	if (!cstr)
		return (NULL);
	cstr = format_hash(cstr, f);
	if (!cstr)
		return (NULL);
	return (cstr);
}

static char	*format_plus(char	*cstr, t_format *f)
{
	int		nb;
	char	*cfstr;

	if ((f->plus || f->space) && (f->type == 'd' || f->type == 'i'))
	{
		nb = ft_atoi(cstr);
		if (nb < 0)
			return (cstr);
		cfstr = ft_calloc(sizeof(char), 2);
		if (!cfstr)
			return (NULL);
		if (f->plus)
			cfstr[0] = '+';
		else
			cfstr[0] = ' ';
		cfstr = han_strcat(cfstr, cstr);
		if (!cfstr)
			return (NULL);
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}

static char	*format_hash(char	*cstr, t_format *f)
{
	char	*cfstr;

	if (f->hash && (f->type == 'x' || f->type == 'X'))
	{
		cfstr = ft_calloc(sizeof(char), 3);
		if (!cfstr)
			return (NULL);
		cfstr[0] = '0';
		if (cstr[0] != '0')
		{
			cfstr[1] = f->type;
			cfstr = han_strcat(cfstr, cstr);
			if (!cfstr)
				return (NULL);
		}
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}
