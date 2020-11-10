/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:21:59 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/06/13 16:58:37 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t		ft_strchri(const char *s, int c)
{
	char		*str;
	size_t		count;

	count = 0;
	str = (char *)s;
	while (str[count] != c)
	{
		if (*str == '\0')
		{
			return (0);
		}
		count++;
	}
	return (count);
}
