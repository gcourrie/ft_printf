/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_extraction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <gcourrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:43:51 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/03 12:26:13 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fonction.h"

void	va_arg_extraction(va_list ap, t_width width, char type, long long *n)
{
	if (type == 'i')
	{
		if (width.l == 1)
			*n = va_arg(ap, long);
		else if (width.l > 1)
			*n = va_arg(ap, long long);
		else
			*n = va_arg(ap, int);
	}
	else if (type == 'u')
	{
		if (width.l == 1)
			*n = va_arg(ap, unsigned long);
		else if (width.l > 1)
			*n = va_arg(ap, unsigned long long);
		else
			*n = va_arg(ap, unsigned int);
	}
	return ;
}
