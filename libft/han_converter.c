/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:51 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 15:08:43 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "libft.h"

static int	baselen(size_t nb);

char	*han_itoh(size_t nb)
{
	char	*base;
	char	*str;
	int		i;

	base = "0123456789abcdef";
	str = ft_calloc(sizeof(char), baselen(nb) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	i = 0;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	han_reversstr(str);
	return (str);
}

static int	baselen(size_t nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}
