/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 21:32:23 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/03 12:27:13 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FONCTION_H
# define FT_FONCTION_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../includes/libft.h"

typedef struct	s_width
{
    int			l;
    int			h;
    int			j;
    int			z;
	int			htag;
	char		zero;
	char		more;
	char		less;
    int			max;
    int			min;
    int			pre;
    int			error;
    int			n;
	int			this;
	char		*str;
}				t_width;

typedef struct	s_struct
{
	char		type;
	t_width		(*f)(va_list ap, t_width width);
}				t_struct;

t_width			ft_flags_checker(va_list ap, const char *format,
								  int *i, t_width width);
int				ft_printf(const char *format, ...);
t_width			ft_d(va_list ap, t_width width);
t_width			ft_s(va_list ap, t_width width);
t_width			ft_u(va_list ap, t_width width);
t_width			ft_o(va_list ap, t_width width);
t_width			ft_x(va_list ap, t_width width);
t_width			ft_c(va_list ap, t_width width);
t_width			ft_p(va_list ap, t_width width);
t_width			ft_prc(va_list ap, t_width width);
t_width			ft_xx(va_list ap, t_width width);
t_width			ft_uu(va_list ap, t_width width);
t_width			ft_oo(va_list ap, t_width width);
t_width			ft_dd(va_list ap, t_width width);
t_width			ft_cc(va_list ap, t_width width);
t_width			ft_ss(va_list ap, t_width width);
t_width			ft_null(va_list ap, t_width width);
char			*ft_minrange(int n, char *str, char c, char s);
char			*ft_precision(char *str, int n);
void			va_arg_extraction(va_list ap, t_width width, char type, long long *n);

#endif
