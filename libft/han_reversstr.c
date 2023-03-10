/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han_reversstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:40 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 15:08:59 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

char	*han_reversstr(char *str)
{
	char	c;
	int		i;
	int		n;

	if (!str)
		return (str);
	i = 0;
	n = ft_strlen(str);
	while (i < n / 2)
	{
		c = str[n - i - 1];
		str[n - i - 1] = str[i];
		str[i] = c;
		i++;
	}
	return (str);
}
