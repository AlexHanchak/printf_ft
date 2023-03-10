/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:34:15 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/13 15:11:32 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

int		han_binstrlen(char *str);
char	*han_itoh(size_t nb);
char	*han_reversstr(char *str);
char	*han_strcat(char *s1, char *s2);
void	*han_relloc(void *ptr, size_t nsize);
char	*han_strtouper(char *str);
size_t	han_memlen(void *ptr);

#endif
