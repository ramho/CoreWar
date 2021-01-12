/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:57 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/12 17:36:27 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

// if no file " Can't read source file %s"

int valid_file(t_asm *champ, char *file_name)
{
	int len;

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

int create_cor_file(t_asm *champ)
{
	int fd;

	ft_strcat(champ->file_name, ".cor");
	if ((fd = open(champ->file_name, O_WRONLY | O_CREAT, 0644)) == -1)
		printf("Error: FD [%d]\n", fd); // add in error
	return (fd);
}
