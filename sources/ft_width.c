/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:20:47 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/09 18:09:23 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_flags.h"

static t_width		ft_check_widthmax(va_list ap, const char *format,
										int *index, t_width width)
{
	if (format[*index] == '.')
	{
		width.pre = 1;
		*index += 1;
		if (format[*index] == '*')
			width.min = va_arg(ap, int);
		else
			while (format[*index] >= '0' && format[*index] <= '9')
			{
				width.max *= 10;
				width.max = width.max + (int)(format[*index] - '0');
				*index += 1;
			}
	}
	return (width);
}

static t_width		ft_check_widthmin(va_list ap, const char *format,
										int *index, t_width width)
{
	if (format[*index] == '*')
		width.min = va_arg(ap, int);
	else
		while (format[*index] >= '0' && format[*index] <= '9')
		{
			width.min *= 10;
			width.min = width.min + (int)(format[*index] - '0');
			*index += 1;
		}
	return (width);
}

static t_width		ft_check_flags(const char *format, int *index, t_width width)
{
	while (format[*index])
	{
		if (format[*index] == '#')
			width.htag += 1;
		else if (format[*index] == '0')
			width.zero = '0';
		else if (format[*index] == '+')
			width.more = '+';
		else if (format[*index] == '-')
			width.less = '-';
		else if (format[*index] == ' ')
			;
		else
			return (width);
		*index += 1;
	}
	return (width);
}

static t_width	reset_global(t_width width)
{
	width.l = 0;
	width.h = 0;
	width.j = 0;
	width.z = 0;
	width.htag = 0;
	width.zero = ' ';
	width.more = ' ';
	width.less = ' ';
	width.min = 0;
	width.max = 0;
	width.pre = 0;
	width.error = 0;
	width.n = 0;
	width.this = 0;
	width.str = NULL;
	return (width);
}

static t_width		ft_check_type(const char *format, int *index, t_width width)
{
	while (format[*index])
	{
		if (format[*index] == 'l')
			width.l += 1;
		else if (format[*index] == 'h')
			width.h += 1;
		else if (format[*index] == 'j')
			width.j += 1;
		else if (format[*index] == 'z')
			width.z += 1;
		else
			return (width);
		*index += 1;
	}
	return (width);
}

t_width			ft_flags_checker(va_list ap, const char *format,
									int *i, t_width width)
{
	int				index;

	index = *i;
	width = reset_global(width);
	while (format[*i] != g_printf2[width.n].type && format[*i])
	{
		if (!(g_printf2[width.n].type) && !(width.n = 0))
			*i += 1;
		else
			width.n += 1;
	}
	width = ft_check_flags(format, &index, width);
	width = ft_check_widthmin(ap, format, &index, width);
	width = ft_check_widthmax(ap, format, &index, width);
	width = ft_check_type(format, &index, width);
	if (index != *i || !(format[*i]) || !(g_printf2[width.n].type))
	{
		width.error = 1;
		*i = index;
	}
	else
		*i += 1;
	return (width);
}
