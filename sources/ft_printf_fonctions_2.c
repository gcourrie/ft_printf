/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fonctions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:24:00 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/09 17:51:13 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fonction.h"

t_width				ft_c(va_list ap, t_width width)
{
	if (!(width.str = (char *)malloc(sizeof(char) * 2)))
		return (width);
	width.str[0] = (char)va_arg(ap, int);
	width.str[1] = '\0';
	if (width.pre == 1 && (int)ft_strlen(width.str) > width.max)
		width.str = ft_precision(width.str, width.max);
	if (width.pre == 1 && (int)ft_strlen(width.str) < width.max)
		width.str = ft_minrange(width.max, width.str, '0', ' ');
	if (width.min > (int)ft_strlen(width.str))
		width.str = ft_minrange(width.min - 1, width.str, width.zero, width.less);
	if (width.min > 1)
		width.this = width.min;
	else
		width.this = 1;
	return (width);
}

t_width				ft_p(va_list ap, t_width width)
{
	void			*p;

	p = va_arg(ap, void *);
	if (!(width.str = malloc(sizeof(char) * 3)))
	return (width);
	width.str[0] = '0';
	width.str[1] = 'x';
	width.str[2] = '\0';
	width.str = ft_strjoin_free(width.str,
								ft_itoa_base((long long)p, 16, 0));
	if (width.pre == 1 && (int)ft_strlen(width.str) > width.max)
		width.str = ft_precision(width.str, width.max);
	if (width.pre == 1 && (int)ft_strlen(width.str) < width.max)
		width.str = ft_minrange(width.max, width.str, '0', ' ');
	if (width.min > (int)ft_strlen(width.str))
		width.str = ft_minrange(width.min, width.str, width.zero, width.less);
	width.this = ft_strlen(width.str);
	return (width);
}

t_width				ft_prc(va_list ap, t_width width)
{
	(void)ap;
	if (!(width.str = (char *)malloc(sizeof(char) * 2)))
		return (width);
	width.str[0] = '%';
	width.str[1] = '\0';
	return (width);
}

t_width				ft_xx(va_list ap, t_width width)
{
	unsigned int	xx;

	xx = va_arg(ap, unsigned int);
	width.str = ft_itoa_base(xx, 16, 1);
	return (width);
}

t_width				ft_null(va_list ap, t_width width)
{
	(void)ap;
	width.str = NULL;
	if (width.pre == 1 && (int)ft_strlen(width.str) > width.max)
		width.str = ft_precision(width.str, width.max);
	if (width.pre == 1 && (int)ft_strlen(width.str) < width.max)
		width.str = ft_minrange(width.max, width.str, '0', ' ');
	if (width.min > (int)ft_strlen(width.str))
		width.str = ft_minrange(width.min, width.str, width.zero, width.less);
	width.this = ft_strlen(width.str);
	return (width);
}
