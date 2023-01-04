/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lex <lex@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:27:46 by lex               #+#    #+#             */
/*   Updated: 2023/01/04 18:28:23 by lex              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

char	*conversion_x(unsigned int nb, int is_upper)
{
	char	*hex;

	hex = han_itoh(nb);
	if (!hex)
		return (NULL);
	if (is_upper)
		hex = han_strtouper(hex);
	return (hex);
}
