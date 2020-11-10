/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:48:50 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/09 16:46:14 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	init_function(int (*conversion[122])(t_base *all))
{
	conversion[99] = c_conversion;
	conversion[112] = p_conversion;
	conversion[115] = s_conversion;
	conversion[100] = di_conversion;
	conversion[105] = di_conversion;
	conversion[111] = o_conversion;
	conversion[117] = u_conversion;
	conversion[120] = x_conversion;
	conversion[88] = xupper_conversion;
	conversion[102] = f_conversion;
	conversion[37] = modulo_conversion;
}

int		start_conversion(t_base *all)
{
	int	ret;
	int	(*conversion[122])(t_base *all);

	init_function(conversion);
	ret = conversion[all->type](all);
	return (ret);
}
