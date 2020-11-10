/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:08:30 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/07 15:37:39 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str, int c, size_t len)
{
	unsigned int	i;
	char			*ptr;

	ptr = str;
	i = 0;
	while (i < len)
	{
		*(ptr + i++) = c;
	}
	return ((void *)str);
}
