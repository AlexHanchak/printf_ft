/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:27:56 by lex               #+#    #+#             */
/*   Updated: 2023/01/07 13:08:52 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*conversion_c(char c)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}
