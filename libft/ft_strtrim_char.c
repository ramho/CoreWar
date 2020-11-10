/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:16:22 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/04/29 14:47:51 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_char(char const *s, char c)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		j = ft_strlen(s) - 1;
		while (s[j] == c && j > i)
			j--;
		str = ft_strsub(s, i, j - (size_t)i + 1);
		return (str);
	}
	return (NULL);
}
