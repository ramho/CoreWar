/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:57 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/02/08 14:16:10 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		valid_file(t_asm *champ, char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (file_name[len - 2] == '.' && file_name[len - 1] == 's')
	{
		if (!(champ->file_name = ft_strsub(file_name, 0, len - 2)))
			malloc_error(champ, "valid_file.c");
		return (1);
	}
	file_error(champ, file_name, 1);
	return (0);
}

/*
**	l64:	check if there is a comment in the line. If so, save the line up to
**			comment char.
*/

void	get_file(char *file, t_asm *champ, int fd)
{
	int		end;
	char	*line;
	char	*buf;

	champ->row = 1;
	if ((fd = open(file, O_RDONLY)) <= 0)
		file_error(champ, file, 2);
	if (!(champ->header = ft_memalloc(sizeof(header_t))))
		file_error(champ, file, 3);
	while ((get_next_line(fd, &line) > 0))
	{
		end = ft_pos_i(line, '#');
		line = ft_strsub(line, 0, end); // malloc free to check
		if ((buf = ft_strchr(line, '.')))
			get_name_comment(buf, champ, ft_strlen(line));
		else
		{
			parse_token(line, champ);
		}
		free(line);
		champ->row++;
	}
}

int		create_cor_file(t_asm *champ)
{
	int	fd;

	ft_strcat(champ->file_name, ".cor");
	if ((fd = open(champ->file_name, O_WRONLY | O_CREAT, 0644)) == -1)
		printf("Error: FD [%d]\n", fd); // add in error
	return (fd);
}
