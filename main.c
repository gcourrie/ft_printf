/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:03:48 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/02 15:59:07 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./includes/ft_fonction.h"

int		main(void)
{
	ft_printf("%c\n", 0);
	ft_printf("%010d\n", -42);
	ft_printf("%3c\n", 'e');
	ft_printf("%23.4d\n", 42);
	ft_printf("%15.4d\n", -42);
	ft_printf("%.4d\n", -424242);
//
	ft_printf("\n");
//
	printf("%c\n", 0);
	printf("%010d\n", -42);
	printf("%3c\n", 'e');
	printf("%23.4d\n", 42);
	printf("%15.4d\n", -42);
	printf("%.4d\n", -424242);
	return (0);
}
