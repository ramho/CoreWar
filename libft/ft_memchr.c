/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:49:46 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/02 18:14:19 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c2;
	size_t			i;
	unsigned char	*s1;

	c2 = (unsigned char)c;
	s1 = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c2)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
