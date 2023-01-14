/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han_memlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:47 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 15:08:49 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	han_memlen(void *ptr)
{
	char	*str;
	size_t	n;

	n = 0;
	str = (char *) ptr;
	while (*str++)
		n++;
	return (n);
}
