/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lex <lex@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:28:15 by lex               #+#    #+#             */
/*   Updated: 2023/01/04 18:28:16 by lex              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "tools.h"

char	*conversion_s(char *s)
{
	char	*str;

	if (s)
		str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	else
		str = ft_calloc(sizeof(char), S_EMPTY_L + 1);
	if (!str)
		return (NULL);
	if (s)
		str = ft_memcpy(str, s, ft_strlen(s));
	else
		str = ft_memcpy(str, S_EMPTY, S_EMPTY_L);
	return (str);
}
