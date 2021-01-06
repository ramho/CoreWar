/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/06 16:19:03 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

// Syntax error at token
// Lexical error at [3:1}
// Syntax error at token [TOKEN][002:002] INSTRUCTION "ld" lde.s

// Invalid parameter [2(0-2)] type [register] for instruction [ld]

void get_file(char *file, t_asm *champ)
{
	int fd;
	int row;
	char *line;
	char *buf;

	row = 1;
	if((fd = open(file, O_RDONLY)) <= 0)
		file_error(champ, file, 2);
	if(!(champ->header = ft_memalloc(sizeof(header_t))))
	{
		free(champ);
		exit(-1);
	}
	while ((get_next_line(fd, &line) > 0))
	{
		if ((buf = ft_strchr(line, '.')))
			get_name_comment(buf, champ, row, ft_strlen(line));
		else
		{
			parse_token(line, champ, row);
		}
		free(line);
		row++;
	}
}

void parse_token(char *line, t_asm *champ, int row)
{
	int i;
	int flag;
	char *ret;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	while(line && line[i] != '\0' && line[i] != '\n')
	{
		flag = i;
		while (ft_strchr(LABEL_CHARS, line[i]))
			i++;
		ret = ft_strsub(line, flag, i - flag);
		if (ft_isspace(line[i]))
			check_label_error(line, i, row);
		if (line[i] == '#' || line[i] == ';')
			return;
		if (line[i] == LABEL_CHAR)
			i = parse_label(line, i, row);
		else if (line[i] == ' ')
		{// find occurence of *str in a table //check id no :
			check_op(ret, line + flag, i - flag,  row, flag + 1);
			return ;
		}
		i++;
	}
}
