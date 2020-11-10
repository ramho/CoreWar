/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:48:59 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/10 17:52:21 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		flag_zero(int *i, t_base *all, char *str)
{
	all->flag.zero = 1;
	while (str[*i] == '0' && !is_type(str[*i + 1]))
		*i += 1;
}

void		width(int *i, t_base *all, char *str)
{
	while (str[*i] == '0')
		*i += 1;
	all->flag.width = ft_atoi(str + *i);
	*i += ft_count_num(all->flag.width);
}

void		precision(int *i, t_base *all, char *str)
{
	*i += 1;
	while (str[*i] == '0')
		*i += 1;
	if (ft_isdigit(str[*i]))
	{
		all->flag.precision = ft_atoi(str + *i);
		*i += ft_count_num(all->flag.precision);
	}
	else
	{
		all->flag.precision = 0;
		*i -= 1;
	}
}

void		flag_l_h(int *i, t_base *all, char *str)
{
	str[*i] == 'L' ? all->flag.upperl = 1 : 0;
	if (str[*i] == 'h')
	{
		all->flag.h = 1;
		if (str[*i + 1] == 'h')
		{
			all->flag.h = 2;
			*i += 1;
		}
	}
	else if (str[*i] == 'l')
	{
		all->flag.l = 1;
		if (str[*i + 1] == 'l')
		{
			all->flag.l = 2;
			*i += 1;
		}
	}
}
