/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:42:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/04/29 13:59:38 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long long	nlen(unsigned long long value, int base)
{
	int				count;

	count = 0;
	while (value)
	{
		count++;
		value /= base;
	}
	return (count);
}

static	char		*pick_size(char c)
{
	if (c == 'm')
		return ("0123456789abcdef");
	else if (c == 'M')
		return ("0123456789ABCDEF");
	return (NULL);
}

char				*ft_u_itoa_base(unsigned long long value, int base, char c)
{
	char			*str_base;
	char			*dst;
	int				len;

	str_base = pick_size(c);
	len = nlen(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[len] = '\0';
	while (value)
	{
		dst[--len] = str_base[value % base];
		value /= base;
	}
	return (dst);
}
