/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han_binstrlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:58 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 17:12:03 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	han_binstrlen(char *str)
{
	int		n;

	n = ft_strlen(str);
	if (n == 0)
		return (1);
	else
		return (n);
}
