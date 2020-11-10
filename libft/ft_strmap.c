/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:03:21 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/04/29 14:54:11 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*s1;
	size_t		i;

	if (s == NULL)
		return (NULL);
	s1 = ft_strdup((const char *)s);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	if (s && f)
	{
		while (s1[i] != '\0')
		{
			s1[i] = f(s1[i]);
			i++;
		}
	}
	return (s1);
}
