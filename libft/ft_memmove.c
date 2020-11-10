/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:22:55 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/20 13:19:28 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (src == NULL && dst == NULL && len != 0)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr < ptr2)
		while (i < len)
		{
			ptr[i] = ptr2[i];
			i++;
		}
	else
	{
		while (len-- > 0)
			ptr[len] = ptr2[len];
	}
	return (dst);
}
