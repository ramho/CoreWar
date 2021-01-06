/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:25:43 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/06 18:29:28 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strstri(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	char	*haystack2;

	haystack2 = (char *)haystack;
	if (needle[0] == '\0')
		return (0);
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
			return (k);
		i = k;
		i++;
	}
	return (0);
}
