/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han_relloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lex <lex@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:44 by lex               #+#    #+#             */
/*   Updated: 2023/01/04 18:29:45 by lex              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

void	*han_relloc(void *ptr, size_t size)
{
	void	*new;
	size_t	msize;

	msize = han_memlen(ptr);
	if (size <= msize)
		return (ptr);
	new = malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	if (!ptr)
		return (new);
	ft_memcpy(new, ptr, msize);
	free(ptr);
	ptr = NULL;
	return (new);
}
