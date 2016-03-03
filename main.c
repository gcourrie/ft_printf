/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:03:48 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/03 10:36:28 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./includes/ft_fonction.h"

int		main(void)
{
	ft_printf("%c\n", 0);
	ft_printf("%010d\n", -42);
	ft_printf("%3c\n", 'e');
	ft_printf("%23.4d\n", 42);
	ft_printf("%15.4d\n", -42);
	ft_printf("%.4d\n", -424242);
	/* ft_printf("%hhd", CHAR_MAX + 42); */
//
	ft_printf("\n");
//
	printf("%c\n", 0);
	printf("%010d\n", -42);
	printf("%3c\n", 'e');
	printf("%23.4d\n", 42);
	printf("%15.4d\n", -42);
	printf("%.4d\n", -424242);
	/* printf("%hhd", CHAR_MAX + 42); */
	return (0);
}
