/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:48:59 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/10 17:52:21 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flag		init_flag(t_flag flag)
{
	flag.hash = 0;
	flag.zero = 0;
	flag.plus = 0;
	flag.minus = 0;
	flag.space = 0;
	flag.width = 0;
	flag.precision = -1;
	flag.l = 0;
	flag.h = 0;
	flag.upperl = 0;
	flag.sign = "+\0";
	return (flag);
}

int			no_conversion_char(char *str, t_base *all)
{
	if (is_flag_char(str[ft_strlen(str) - 1])
		|| ft_isdigit(str[ft_strlen(str) - 1]))
		return (1);
	write(1, &str[ft_strlen(str) - 1], 1);
	all->count += 1;
	return (1);
}

int			light_flags_bis(int *i, char *str, t_base *all)
{
	while (str[*i] && !(is_type(str[*i])))
	{
		if (str[*i] == '0')
			flag_zero(i, all, str);
		str[*i] == '#' ? all->flag.hash = 1 : 0;
		str[*i] == '+' ? all->flag.plus = 1 : 0;
		str[*i] == '-' ? all->flag.minus = 1 : 0;
		str[*i] == ' ' ? all->flag.space = 1 : 0;
		if (ft_isdigit(str[*i]) && all->flag.width == 0)
			width(i, all, str);
		if (str[*i] == '.')
			precision(i, all, str);
		if (str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'L')
			flag_l_h(i, all, str);
		if (!is_type(str[*i]))
			*i += 1;
	}
	return (1);
}

int			light_flags(t_base *all, char *str)
{
	int		i;

	i = 0;
	all->malloc = 0;
	if (!((is_type(str[ft_strlen(str) - 1])) || str[ft_strlen(str) - 1] == '%'))
		return (no_conversion_char(str, all));
	all->flag = init_flag(all->flag);
	light_flags_bis(&i, str, all);
	all->type = str[i];
	all->flag.minus == 1 ? all->flag.zero = 0 : 0;
	all->flag.plus == 1 ? all->flag.space = 0 : 0;
	all->flag.width == 0 ? all->flag.zero = 0 : 0;
	return (start_conversion(all));
}
