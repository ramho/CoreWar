/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:18:10 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/10 18:22:34 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*o_conversion_bis(uintmax_t nb, t_base *all, char *s)
{
	if (nb == 0 && all->flag.precision == 0)
	{
		if (all->flag.hash == 1)
		{
			free(s);
			if ((s = ft_strdup("0")) == NULL)
				return (NULL);
		}
		else
			ft_bzero(s, ft_strlen(s));
	}
	return (s);
}

int				o_conversion(t_base *all)
{
	uintmax_t	nb;
	char		*s;
	int			len;

	nb = 0;
	nb = check_l_ll_h_hh_unsigned(nb, all);
	if (!(s = ft_u_itoa_base(nb, 8, 'm')))
		return (-1);
	len = ft_strlen(s);
	if (!(o_conversion_bis(nb, all, s)))
		return (free_2(s));
	if (!(s = precision_dioux(all, s)))
		return (free_2(s));
	if (all->flag.hash == 1 && all->flag.precision <= len && nb >= 1)
	{
		if (!(s = ft_strjoin_n_free("0", s, 2)))
			return (free_2(s));
		all->flag.hash = 0;
	}
	if (!(ft_flag_width(all, s)))
		return (free_2(s));
	fill_width_space(all, all->con_str, all->tot_len);
	final_conversion(all, s);
	free(s);
	return (all->tot_len);
}

int				u_conversion(t_base *all)
{
	uintmax_t	nb;
	char		*s;

	all->flag.plus ? all->flag.plus = 0 : 0;
	all->flag.minus ? all->flag.zero = 0 : 0;
	all->flag.space ? all->flag.space = 0 : 0;
	nb = 0;
	nb = check_l_ll_h_hh_unsigned(nb, all);
	if (!(s = ft_u_itoa_base(nb, 10, 'm')))
		return (-1);
	if (all->flag.precision == 0 && nb == 0)
		all->flag.hash == 1 ? s = ft_strdup("0") : ft_bzero(s, ft_strlen(s));
	if (!(s = precision_dioux(all, s)))
		return (free_2(s));
	if (!(ft_flag_width(all, s)))
		return (free_2(s));
	fill_width_space(all, all->con_str, all->tot_len);
	final_conversion(all, s);
	free(s);
	return (all->tot_len);
}

int				x_conversion(t_base *all)
{
	uintmax_t	nb;
	char		*s;

	nb = 0;
	nb = check_l_ll_h_hh_unsigned(nb, all);
	if (!(s = ft_u_itoa_base(nb, 16, 'm')))
		return (-1);
	if (nb == 0 && all->flag.precision == 0)
		ft_bzero(s, ft_strlen(s));
	if (!(s = precision_dioux(all, s)))
		return (free_2(s));
	if (all->flag.hash == 1 && ((all->flag.precision >= 0 && nb > 0)
		|| (all->flag.zero == 0 && nb > 0)))
	{
		if (!(s = ft_strjoin_n_free("0x", s, 2)))
			return (free_2(s));
		all->flag.hash = 0;
	}
	if (!(ft_flag_width(all, s)))
		return (free_2(s));
	fill_width_space(all, all->con_str, all->tot_len);
	final_conversion(all, s);
	free(s);
	return (all->tot_len);
}

int				xupper_conversion(t_base *all)
{
	uintmax_t	nb;
	char		*s;

	nb = 0;
	nb = check_l_ll_h_hh_unsigned(nb, all);
	if (!(s = ft_u_itoa_base(nb, 16, 'M')))
		return (-1);
	if (nb == 0 && all->flag.precision == 0)
		ft_bzero(s, ft_strlen(s));
	if (!(s = precision_dioux(all, s)))
		return (free_2(s));
	if (all->flag.hash == 1 && ((all->flag.precision >= 0 && nb > 0)
		|| (all->flag.zero == 0 && nb > 0)))
	{
		if (!(s = ft_strjoin_n_free("0X", s, 2)))
			return (free_2(s));
		all->flag.hash = 0;
	}
	if (!(ft_flag_width(all, s)))
		return (free_2(s));
	fill_width_space(all, all->con_str, all->tot_len);
	final_conversion(all, s);
	free(s);
	return (all->tot_len);
}
