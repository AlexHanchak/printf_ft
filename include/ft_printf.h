/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:53:34 by ohanchak          #+#    #+#             */
/*   Updated: 2022/12/22 20:52:25 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

// formats/flags
typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_prec;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}			t_format;

# define INT_MIN -2147483648
# define UINT_MAX 4294967295
// specifiers
# define SPECIFIERS	"cspdiuxX%"
# define HEXALOW	"0123456789abcdef"
# define HEXAUP		"0123456789ABCDEF"

int			ft_printf(const char *str, ...);

/* Initializes default parameters for new format struct */
t_format	ft_newformat(void);

/* Calls printing function depending on the specifier */
int			ft_print_format(t_format f, va_list ap);

/*numbers leng*/
int			ft_nbrlen(long n, int base);

/*write numbchar*/
int			ft_putnchar_fd(char c, int fd, int n);

/*write stringnumb*/
int			ft_putstrn_fd(char *s, int fd, int n);

/*print nmb <-> char*/
int			ft_putnchr_fd(char c, int fd, int n);

/* Prints chars with format */
int			ft_print_c_pct(t_format f, va_list ap);

/* Prints strings with format */
int			ft_print_s(t_format f, va_list ap);

/* Prints decimal number with format */
int			ft_print_d_i_u(t_format f, va_list ap);

/* Prints hexadecimal number with format */
int			ft_print_x(t_format f, va_list ap);

/* Prints 0x followed by a hexadecimal number with format */
int			ft_print_p(t_format f, va_list ap);

/* Checks the str after a '%' is found and fills struct */
int			ft_parse(char *str, va_list	ap);

#endif
