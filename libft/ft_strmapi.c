/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:15:18 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/04/29 13:45:49 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	s1 = ft_strdup((const char *)s);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	if (s1 && f)
	{
		while (s[i] != '\0')
		{
			s1[i] = f(i, s1[i]);
			i++;
		}
	}
	return (s1);
}
