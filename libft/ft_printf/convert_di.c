/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:18:10 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/10 18:22:34 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*di_conversion_thrice(t_base *all, char *s)
{
	int			i;

	i = -1;
	if (all->flag.minus)
	{
		if (all->flag.space == 1 && all->flag.zero == 0)
		{
			if (!(s = ft_strjoin_n_free(" \0", s, 2)))
				return (NULL);
			all->len += 1;
			all->flag.space = 0;
		}
		while (++i <= all->len - 1)
		{
			all->con_str[i] = s[i];
		}
	}
	else
	{
		i = all->tot_len;
		while (all->len + 1)
			all->con_str[i--] = s[all->len--];
	}
	return (all->con_str);
}

char			*di_conversion_twice(intmax_t nb, t_base *all, char *s)
{
	if (nb == 0 && all->flag.precision == 0)
		ft_bzero(s, ft_strlen(s));
	if (!(s = precision_dioux(all, s)))
		return (NULL);
	if ((all->flag.plus == 1 || all->signed_nb < 0) && all->flag.zero == 0)
	{
		if (!(s = ft_strjoin_n_free(all->flag.sign, s, 2)))
			return (free_3(s));
		all->flag.plus = 0;
	}
	if (all->flag.space == 1 && all->flag.precision >= 0)
	{
		if (!(s = ft_strjoin_n_free(" \0", s, 2)))
			return (free_3(s));
		all->flag.space = 0;
	}
	return (s);
}

int				di_conversion(t_base *all)
{
	intmax_t	nb;
	char		*s;

	nb = 0;
	nb = check_l_ll_h_hh(nb, all);
	nb < 0 ? all->flag.sign = "-\0" : all->flag.sign;
	nb < 0 ? all->flag.space = 0 : 0;
	nb < 0 ? nb = -nb : nb;
	if (!(s = ft_u_itoa_base(nb, 10, 'm')))
		return (-1);
	if (!(s = di_conversion_twice(nb, all, s)))
		return (free_2(s));
	if (!ft_flag_width(all, s))
		return (free_2(s));
	fill_width_space(all, all->con_str, all->tot_len);
	if (!(di_conversion_thrice(all, s)))
		return (-1);
	all->con_str[all->tot_len] = '\0';
	if (all->flag.space == 1)
		all->con_str[0] = ' ';
	ft_putstr(all->con_str);
	all->count += ft_strlen(all->con_str);
	free(all->con_str);
	free(s);
	return (ft_strlen(all->con_str));
}
