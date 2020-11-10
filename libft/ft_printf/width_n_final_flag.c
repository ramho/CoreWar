/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_n_final_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:18:10 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/10 18:22:34 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_flag_width(t_base *all, char *s)
{
	all->len = ft_strlen(s);
	all->tot_len = (all->len <= all->flag.width) ? all->flag.width : all->len;
	if (!(all->con_str = malloc(sizeof(char *) * (all->tot_len + 1))))
		return (-1);
	return (1);
}

void		fill_width_space(t_base *all, char *str, int size)
{
	int		i;

	i = 0;
	if (all->flag.zero == 1)
	{
		while (i < size)
			str[i++] = '0';
		if (all->flag.plus == 1 || all->signed_nb < 0)
		{
			str[0] = *all->flag.sign;
			all->flag.plus = 0;
		}
		if (all->flag.hash == 1 && all->signed_nb != 0 && (all->type == 'x'
		|| all->type == 'X'))
		{
			str[0] = '0';
			all->type == 'x' ? str[1] = 'x' : 0;
			all->type == 'X' ? str[1] = 'X' : 0;
		}
	}
	else
	{
		while (i < size)
			str[i++] = ' ';
	}
}

void		final_conversion(t_base *all, char *s)
{
	int		i;

	i = -1;
	all->con_str[all->tot_len] = '\0';
	if (all->flag.minus)
	{
		while (++i <= all->len - 1)
			all->con_str[i] = s[i];
	}
	else
	{
		i = all->tot_len;
		while (all->len + 1)
			all->con_str[i--] = s[all->len--];
	}
	all->con_str[all->tot_len + 1] = '\0';
	ft_putstr(all->con_str);
	all->count += ft_strlen(all->con_str);
	free(all->con_str);
}
