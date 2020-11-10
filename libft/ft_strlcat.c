/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:51:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/03 12:18:10 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*dst;
	const char	*s;
	size_t		n;
	size_t		dlen;

	dst = dest;
	s = src;
	n = size;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*dst++ = *s;
			n--;
		}
		s++;
	}
	*dst = '\0';
	return (dlen + (s - src));
}
