/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:48:50 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/09 16:46:14 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*precision_s(t_base *all, char *s)
{
	char	*tmp;

	if (all->flag.precision > 0 && all->flag.precision < (int)ft_strlen(s))
	{
		if (!(tmp = ft_strsub(s, 0, all->flag.precision)))
			return (NULL);
		s = tmp;
		all->malloc = 1;
	}
	else
		return (s);
	return (s);
}

char		*precision_dioux_bis(t_base *all, char *s)
{
	int		diff;
	char	*tmp;

	tmp = NULL;
	all->flag.zero = 0;
	diff = all->flag.precision - ft_strlen(s);
	if (!(tmp = fill_zero(diff)))
		return (NULL);
	if (!(tmp = ft_strjoin_n_free(tmp, s, 3)))
		return (free_3(tmp));
	if (all->flag.plus == 1 || all->signed_nb < 0)
	{
		if (!(tmp = ft_strjoin_n_free(all->flag.sign, tmp, 2)))
			return (free_3(tmp));
		all->flag.plus = 0;
		if (all->signed_nb < 0)
			all->signed_nb = -all->signed_nb;
	}
	return (tmp);
}

char		*precision_dioux(t_base *all, char *s)
{
	if (all->flag.precision > 0 && all->flag.precision >= (int)ft_strlen(s))
	{
		if ((s = precision_dioux_bis(all, s)) == NULL)
			return (NULL);
	}
	else if (all->flag.space == 1 && all->signed_nb >= 0
	&& all->flag.zero == 0 && (all->type != 'd' || all->type != 'i'))
	{
		if (!(s = ft_strjoin_n_free(" ", s, 2)))
			return (free_3(s));
		all->flag.space = 0;
	}
	else
	{
		all->flag.precision >= 0 ? all->flag.zero = 0 : 0;
		all->flag.width <= (int)ft_strlen(s) ? all->flag.zero = 0 : 0;
		return (s);
	}
	return (s);
}

char		*fill_zero(int size)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
