/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lex <lex@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:28:40 by lex               #+#    #+#             */
/*   Updated: 2023/01/04 18:28:43 by lex              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "tools.h"

static char	*align_left(char *cstr, t_format *f);
static char	*align_right(char *cstr, t_format *f);
static int	fill_prefix(char *cfstr, int i, int n, t_format *f);

char	*conversion_width(char	*cstr, t_format *f)
{
	char	*cfstr;

	if (f->width <= ft_strlen(cstr))
		return (cstr);
	if (f->minus)
		cfstr = align_left(cstr, f);
	else
		cfstr = align_right(cstr, f);
	if (!cfstr)
		return (NULL);
	return (cfstr);
}

static char	*align_left(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		plen;

	i = 0;
	plen = han_binstrlen(cstr);
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	if (!cfstr)
		return (NULL);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (i < f->width)
	{	
		if (i < plen && (f->type == 's' && *cstr == 0))
			cfstr[i] = ' ';
		else if (i < plen)
			cfstr[i] = cstr[i];
		else
			cfstr[i] = ' ';
		i++;
	}
	free(cstr);
	return (cfstr);
}

static char	*align_right(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		j;
	int		plen;

	i = 0;
	j = 0;
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	plen = han_binstrlen(cstr);
	if (!cfstr)
		return (NULL);
	if (cstr[0] == '-' && (f->zero && (!f->dot || f->pcs < 0)))
	{
		cfstr[i++] = cstr[j++];
		f->width++;
	}
	i = fill_prefix(cfstr, i, plen, f);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (j < plen)
		cfstr[i++] = cstr[j++];
	free(cstr);
	return (cfstr);
}

static int	fill_prefix(char *cfstr, int i, int n, t_format *f)
{
	while (i < f->width - n)
	{
		if (f->zero && (!f->dot || f->pcs < 0))
			cfstr[i] = '0';
		else
			cfstr[i] = ' ';
		i++;
	}
	return (i);
}
