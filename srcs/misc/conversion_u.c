/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:28:18 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 15:12:16 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

static char	*uits(unsigned int d);
static int	uilen(unsigned int d);

char	*conversion_u(unsigned int d)
{
	char	*str;

	str = uits(d);
	if (!str)
		return (NULL);
	han_reversstr(str);
	return (str);
}

static char	*uits(unsigned int d)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), uilen(d) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	while (d > 0)
	{
		str[i] = (d % 10) + '0';
		d = d / 10;
		i++;
	}
	return (str);
}

static int	uilen(unsigned int d)
{
	int		i;

	i = 0;
	if (d == 0)
		return (1);
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}
