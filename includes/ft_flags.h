/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 22:58:43 by gcourrie          #+#    #+#             */
/*   Updated: 2016/02/18 14:24:42 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_H
# define FT_FLAGS_H

# include "../includes/ft_fonction.h"

t_struct		g_printf2[] =
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
