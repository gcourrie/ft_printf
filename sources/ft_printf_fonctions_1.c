/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fonctions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:05:00 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/02 17:13:55 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonction.h"

t_width				ft_d(va_list ap, t_width width)
{
	long			d;
	int				n;

	n = 0;
	d = (long)va_arg(ap, int);
	if (d < 0 && (n = 1))
		d *= -1;
	width.str = ft_itoa_base(d, 10, 0);
	if (width.pre == 1 && (int)ft_strlen(width.str) < width.max)
		width.str = ft_minrange(width.max, width.str, '0', ' ');
	if (width.min > (int)ft_strlen(width.str))
		width.str = ft_minrange(width.min, width.str, width.zero, width.less);
	if (n == 1 && !(n = 0))
	{
		while (width.str[n] == ' ')
			n++;
		if (width.str[0] != ' ' && width.str[0] != 0)
			width.str = ft_strjoin_free(ft_strdup("-"), width.str);
		else
			width.str[(n == 0) ? n : (n - 1)] = '-';
	}
	if (width.pre == 1 && width.max == 0)
		width.str = NULL;
	if (width.str == NULL)
        width.str = ft_strdup("(null)");
	width.this = ft_strlen(width.str);
	return (width);
}

t_width				ft_s(va_list ap, t_width width)
{
	width.str = va_arg(ap, char*);
	width.str = ft_strdup(width.str);
	if (width.str == NULL)
        width.str = ft_strdup("(null)");
	width.this = ft_strlen(width.str);
	return (width);
}

t_width				ft_u(va_list ap, t_width width)
{
	long			d;

	d = (long)va_arg(ap, unsigned int);
	width.str = ft_itoa_base(d, 10, 0);
	if (width.str == NULL)
        width.str = ft_strdup("(null)");
	if (width.pre == 1 && (int)ft_strlen(width.str) < width.max)
		width.str = ft_minrange(width.max, width.str, '0', ' ');
	if (width.min > (int)ft_strlen(width.str))
		width.str = ft_minrange(width.min, width.str, width.zero, width.less);
	if (width.pre == 1 && width.max == 0)
		width.str = NULL;
	width.this = ft_strlen(width.str);
	return (width);
}

t_width				ft_o(va_list ap, t_width width)
{
	unsigned int	o;

	o = va_arg(ap, unsigned int);
	width.str = ft_itoa_base(o, 8, 0);
	width.this = strlen(width.str);
	return (width);
}

t_width				ft_x(va_list ap, t_width width)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	width.str = ft_itoa_base(x, 16, 0);
	width.this = strlen(width.str);
	return (width);
}
