/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:29:51 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/09 14:48:59 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_len(const char *str, size_t len)
{
	while (len--)
	{
/* 		if (*str == '\0') */
/* 			ft_putstr("%^"); */
/* 		else */
			ft_putchar(*str);
		str++;
	}
}
