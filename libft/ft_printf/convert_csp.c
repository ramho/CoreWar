/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:48:50 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/09 16:46:14 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int				c_conversion(t_base *all)
{
	char		c;

	c = va_arg(all->args, int);
	all->len = 1;
	all->tot_len = all->flag.width >= all->len ? all->flag.width : all->len;
	if (!(all->con_str = malloc(sizeof(char *) * (all->tot_len + 1))))
		return (-1);
	fill_width_space(all, all->con_str, all->tot_len);
	if (all->flag.minus)
	{
		write(1, &c, 1);
		write(1, all->con_str, all->tot_len - 1);
		all->count += all->tot_len;
		free(all->con_str);
		return (all->tot_len);
	}
	else
	{
		write(1, all->con_str, all->tot_len - 1);
		write(1, &c, 1);
	}
	all->count += all->tot_len;
	free(all->con_str);
	return (all->tot_len);
}

char			*p_conversion_bis(t_base *all, long int p, char *s)
{
	if (p == 0 && all->flag.precision == 0)
	{
		ft_bzero(s, ft_strlen(s));
		all->flag.zero = 0;
	}
	if (all->flag.precision >= 0)
	{
		if (!(s = precision_dioux(all, s)))
			return (NULL);
	}
	else
	{
		if (all->flag.zero == 1)
		{
			if (!(s = ft_strjoin_n_free(fill_zero(all->flag.width -
				(ft_strlen(s) + 2)), s, 3)))
				return (NULL);
			all->flag.zero = 0;
		}
	}
	return (s);
}

int				p_conversion(t_base *all)
{
	char		*s;
	long int	p;

	p = va_arg(all->args, long);
	all->flag.plus = 0;
	if (!(s = ft_itoa_base(p, 16, 'm')))
		return (-1);
	if ((s = p_conversion_bis(all, p, s)) == NULL)
		return (free_2(s));
	if (!(s = ft_strjoin_n_free("0x", s, 2)))
		return (free_2(s));
	if (!(ft_flag_width(all, s)))
		return (free_2(s));
	fill_width_space(all, all->con_str, all->tot_len);
	final_conversion(all, s);
	free(s);
	return (all->tot_len);
}

int				s_conversion(t_base *all)
{
	char		*s;

	s = va_arg(all->args, char*);
	if (s == NULL)
		s = "(null)";
	if (all->flag.precision == 0)
		s = "\0";
	if (!(s = precision_s(all, s)))
		return (-1);
	if (!(ft_flag_width(all, s)))
		return (free_2(s));
	fill_width_space(all, all->con_str, all->tot_len);
	all->con_str[all->tot_len] = '\0';
	final_conversion(all, s);
	if (all->malloc == 1)
		free(s);
	return (all->tot_len);
}
