/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:01:06 by sofchami          #+#    #+#             */
/*   Updated: 2018/11/20 23:43:44 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_clean(char **line, char **line2, int ret, int fd)
{
	ft_strdel(&line[fd]);
	ft_strdel(&(*line2));
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	gnl;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, gnl.buff, 0) < 0 ||
	(!(gnl.rest[fd]) && (gnl.rest[fd] = ft_strnew(0)) == NULL))
		return (-1);
	while (!(ft_strchr(gnl.rest[fd], '\n')) &&
		(gnl.ret = read(fd, gnl.buff, BUFF_SIZE)) > 0)
	{
		gnl.buff[gnl.ret] = '\0';
		gnl.ptr = gnl.rest[fd];
		if (!(gnl.rest[fd] = ft_strjoin(gnl.ptr, gnl.buff)))
			return (ft_clean(&gnl.rest[fd], NULL, -1, fd));
		free(gnl.ptr);
	}
	if (!(*line = ft_strsub(gnl.rest[fd], 0, ft_pos_i(gnl.rest[fd], '\n'))))
		return (ft_clean(&gnl.rest[fd], NULL, -1, fd));
	if (gnl.ret != 0)
		ft_strcpy(gnl.rest[fd], ft_strchr(gnl.rest[fd], '\n') + 1);
	else
		ft_strlen(gnl.rest[fd]) > 0 ? (ft_strcpy(gnl.rest[fd],
			ft_strchr(gnl.rest[fd], '\0'))) : (ft_strdel(&gnl.rest[fd]));
	return (gnl.rest[fd] ? 1 : ft_clean(&gnl.rest[fd], &(*line), 0, 0));
}
