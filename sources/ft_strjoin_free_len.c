/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 22:30:11 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/09 14:35:07 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoin_free_len(char *s1, char *s2,
									int s1_len, int s2_len)
{
	char	*str;
	char	*tmp;
	char	*str1;
	char	*str2;

	str1 = s1;
	str2 = s2;
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	tmp = str;
	while (s1_len--)
		*tmp++ = *str1++;
	while (s2_len--)
		*tmp++ = *str2++;
	*tmp = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}
