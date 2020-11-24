/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/11/24 16:22:17 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

// Syntax error at token
// Lexical error at [3:1]
// Syntax error at token [TOKEN][002:002] INSTRUCTION "ld" lde.s

// Invalid parameter [2(0-2)] type [register] for instruction [ld]

void get_file(char *file, t_asm *champ)
{
	int fd;
	int row;
	char *line;
	char *buf;

	row = 0;
	if((fd = open(file, O_RDONLY)) <= 0)
		file_error(champ, file, 2);
	while ((get_next_line(fd, &line) > 0))
	{
		// printf("[%d] line [%s] line[0] [%c]\n",row, line, line[0]);
		if ((buf = ft_strchr(line, '.')))
			get_name_comment(line, champ);
		free(line);
		row++;
	}
}

void get_name_comment(char *line, t_asm *champ)
{
	// printf("in get name comm\n");
	char *str;
	char **tab;
	static int count = 0;

	champ->header = ft_memalloc(sizeof(header_t));
	if (ft_strstr(line, "name"))
	{
		tab = ft_strsplit(line, '"');
		if (ft_strlen(tab[1]) <= PROG_NAME_LENGTH)
			ft_memcpy(champ->header->prog_name, tab[1], ft_strlen(tab[1]));
		else
		{
			invalid_header(champ, 1);
		}
		count++;
		ft_memdel((void**)tab);
	}
	else if (line[1] == 'c')
	{
		tab = ft_strsplit(line, '"');
		if (ft_strlen(tab[1]) <= COMMENT_LENGTH)
			ft_memcpy(champ->header->comment, tab[1], ft_strlen(tab[1]));
		else
		{
			invalid_header(champ, 2);
		}
		count++;
		ft_memdel((void**)tab);
	}
	// else
	// {
	// 	tab = ft_strsplit(line, 32);
	// 	syntax_error(tab[0], )
	// }
}
void parse_label()
{

}

void parse_op()
{}

void parse_param()
{

}
