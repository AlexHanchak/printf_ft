/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:33:04 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 15:07:42 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*buf;
	char			*temp;

	i = 0;
	buf = (char *) dest;
	temp = (char *) src;
	while (i < n)
	{
		*buf++ = *temp++;
		i++;
	}
	return (dest);
}
