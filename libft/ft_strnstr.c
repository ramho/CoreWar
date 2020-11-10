/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:13:08 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/04/26 15:30:19 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		k;
	int		j;
	char	*haystack2;

	haystack2 = (char *)haystack;
	if (needle[0] == '\0')
		return (haystack2);
	i = 0;
	while (haystack2[i] != '\0')
	{
		j = 0;
		k = i;
		while (haystack2[i] != '\0' && needle[j] != '\0'
				&& haystack2[i] == needle[j] && i < (int)len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (&haystack2[k]);
		i = k;
		i++;
	}
	return (0);
}
