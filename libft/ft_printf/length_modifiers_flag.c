/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifiers_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:48:50 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/09 16:46:14 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

intmax_t		check_l_ll_h_hh(intmax_t nb, t_base *all)
{
	if (all->flag.h > 0 || all->flag.l > 0)
	{
		if (all->flag.l == 1)
			nb = va_arg(all->args, long int);
		else if (all->flag.l == 2)
			nb = va_arg(all->args, long long int);
		else if (all->flag.h == 1)
			nb = (short int)va_arg(all->args, int);
		else if (all->flag.h == 2)
			nb = (char)va_arg(all->args, int);
	}
	else
		nb = va_arg(all->args, int);
	all->signed_nb = nb;
	return (nb);
}

uintmax_t		check_l_ll_h_hh_unsigned(uintmax_t nb, t_base *all)
{
	if (all->flag.h > 0 || all->flag.l > 0)
	{
		if (all->flag.l == 1)
			nb = va_arg(all->args, unsigned long int);
		else if (all->flag.l == 2)
			nb = va_arg(all->args, unsigned long long int);
		else if (all->flag.h == 1)
			nb = (unsigned short int)va_arg(all->args, int);
		else if (all->flag.h == 2)
			nb = (unsigned char)va_arg(all->args, int);
	}
	else
		nb = va_arg(all->args, unsigned int);
	all->signed_nb = nb;
	return (nb);
}

long double		check_l_lupper(t_base *all)
{
	long double	nb;

	if (all->flag.l == 1 || all->flag.upperl == 1)
		nb = va_arg(all->args, long double);
	else
		nb = va_arg(all->args, double);
	all->signed_nb_f = nb;
	return (nb);
}
