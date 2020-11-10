/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:48:50 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/09 16:46:14 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int					convert_f_bis(t_base *all, char *s, char *s_deci)
{
	if (all->flag.precision != 0)
	{
		if (!(s = ft_strjoin_n_free(s, ".", 1)))
			return (free_4(s, s_deci));
		if (!(s = ft_strjoin_n_free(s, s_deci, 3)))
			return (free_4(s, s_deci));
		all->malloc = 1;
	}
	else
	{
		if (all->flag.hash == 1)
		{
			if (!(s = ft_strjoin_n_free(s, ".", 1)))
				return (free_4(s, s_deci));
		}
	}
	if (!(ft_flag_width(all, s)))
		return (-1);
	fill_width_space(all, all->con_str, all->tot_len);
	final_conversion(all, s);
	free(s);
	if (all->malloc == 0)
		free(s_deci);
	return (ft_strlen(all->con_str));
}

void				round_up(long double *nb, int decimal)
{
	long double round;

	round = 0.1;
	if (decimal > 6)
		round = round / 10;
	while (decimal)
	{
		round = round / 10;
		decimal--;
	}
	round *= 10;
	*nb = *nb + round;
}

void				round_float(t_base *all, long double *nb)
{
	int				decimal;
	long long int	intpart;
	long double		tmp_float;

	decimal = (all->flag.precision >= 0) ? all->flag.precision : 6;
	intpart = (signed long long int)*nb;
	tmp_float = *nb - intpart;
	while (decimal--)
	{
		tmp_float = tmp_float * 10;
		tmp_float -= (signed long long int)tmp_float;
	}
	tmp_float = tmp_float * 10;
	intpart = (signed long long int)tmp_float;
	if (intpart >= 5)
	{
		decimal = (all->flag.precision >= 0) ? all->flag.precision : 6;
		round_up(nb, decimal);
	}
}

char				*get_deci_part(long double nb, t_base *all)
{
	long long		intpart;
	char			*str;
	char			*tmp;
	int				decimal;
	int				i;

	i = 0;
	decimal = (all->flag.precision >= 0) ? all->flag.precision : 6;
	intpart = (signed long long int)nb;
	nb = nb - intpart;
	if (!(str = malloc(sizeof(char) * decimal + 1)))
		return (NULL);
	str[decimal] = '\0';
	while (decimal--)
	{
		nb *= 10;
		if (!(tmp = ft_itoa((signed int)nb)))
			return (free_3(str));
		nb -= (signed long int)nb;
		str[i] = tmp[0];
		i++;
		free(tmp);
	}
	return (str);
}

int					f_conversion(t_base *all)
{
	long double		nb;
	char			*str;
	char			*decipart;

	nb = check_l_lupper(all);
	nb < 0 ? all->flag.sign = "-\0" : all->flag.sign;
	nb < 0 ? nb = -nb : nb;
	round_float(all, &nb);
	if (!(str = ft_u_itoa_base((signed long int)nb, 10, 'm')))
		return (-1);
	if (!(decipart = get_deci_part(nb, all)))
		return (free_2(str));
	if (all->flag.plus == 1 || all->signed_nb_f < 0)
	{
		if (!(str = ft_strjoin_n_free(all->flag.sign, str, 2)))
			return (free_4(str, decipart));
		all->flag.space = 0;
	}
	if (all->flag.space == 1)
	{
		if (!(str = ft_strjoin_n_free(" ", str, 2)))
			return (free_4(str, decipart));
	}
	convert_f_bis(all, str, decipart);
	return (1);
}
