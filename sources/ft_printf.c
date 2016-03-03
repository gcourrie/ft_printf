/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:32:03 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/03 12:34:08 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*ft_precision(char *str, int n)
{
	char			*tmp;
	char			*tmp2;
	char			*ret;

	tmp2 = str;
	if (!(ret = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	tmp = ret;
	while (n--)
		*tmp++ = *tmp2++;
	*tmp = '\0';
	free(str);
	return (ret);
}

char				*ft_minrange(int n, char *str, char c, char s)
{
	char			*tmp;
	char			*tmp2;
	char			*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	tmp = ret;
	tmp2 = str;
	if (s == ' ')
		while ((n-- - ft_strlen(str)) > 0)
			*tmp++ = c;
	while (*tmp2)
	{
		*tmp++ = *tmp2++;
		n--;
	}
	if (s == '-')
		while (n--)
			*tmp++ = c;
	*tmp = '\0';
	free(str);
	return (ret);
}

static t_width		ft_fonction(va_list ap, int *nbr,
								t_width width)
{
	(void)nbr;
	width = g_printf[width.n].f(ap, width);
	return (width);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*ret;
	t_width	width;

	width.n = 0;
	i = 0;
	ret = NULL;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i++] == '%')
		{
			if (width.n < (i - 1))
				ret = ft_strjoin_free(ret, ft_strndup(format, width.n, i - 1));
			width = ft_flags_checker(ap, format, &i, width);
			width = ft_fonction(ap, &(width.error), width);
			ret = ft_strjoin_free(ret, width.str);
			width.n = i;
		}
	}
	va_end(ap);
	ret = ft_strjoin_free(ret, ft_strndup(format, width.n, i));
	ft_putstr(ret);
	if (width.error == 1)
		return (-1);
	return (ft_strlen(ret));
}
