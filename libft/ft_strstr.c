/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:11:46 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/21 14:48:27 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
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
			&& haystack2[i] == needle[j])
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
