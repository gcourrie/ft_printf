/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:32:38 by gcourrie          #+#    #+#             */
/*   Updated: 2016/02/16 14:53:26 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../includes/ft_fonction.h"

t_struct		g_printf[] =
{
	{'s', &ft_s},
	{'S', &ft_ss},
	{'p', &ft_p},
	{'d', &ft_d},
	{'D', &ft_dd},
	{'i', &ft_d},
	{'o', &ft_o},
	{'O', &ft_oo},
	{'u', &ft_u},
	{'U', &ft_uu},
	{'x', &ft_x},
	{'X', &ft_xx},
	{'c', &ft_c},
	{'C', &ft_cc},
	{'%', &ft_prc},
	{'\0', &ft_null},
};

#endif
