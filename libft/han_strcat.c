/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han_strcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:37 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 15:09:05 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

char	*han_strcat(char *s1, char *s2)
{
	int		i;
	int		n1;
	int		n2;

	i = 0;
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	s1 = han_relloc((void *) s1, n1 + n2 + 1);
	if (!s1)
		return (NULL);
	while (i < n1)
		i++;
	while (i < n2 + n1)
	{
		s1[i] = s2[i - n1];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
