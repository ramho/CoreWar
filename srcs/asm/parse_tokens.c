/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/08 13:29:06 by rhoorntj         ###   ########.fr       */
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
	char *line;
	char *buf;

	champ->row = 1;
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
			get_name_comment(buf, champ, ft_strlen(line));
		else
		{
			parse_token(line, champ);
		}
		free(line);
		champ->row++;
	}
}

void parse_token(char *line, t_asm *champ)
{
	// int i;
	int flag;
	char *ret;

	champ->i = 0; // can put in init asm.c
	champ->pos = 0; // can put in init of asm.c
	champ->line = line;
	while (ft_isspace(line[champ->i]))
		champ->i++;
	while(line && line[champ->i] != '\0' && line[champ->i] != '\n')
	{
		flag = champ->i;
		while (ft_strchr(LABEL_CHARS, line[champ->i]))
			champ->i++;
		ret = ft_strsub(line, flag, champ->i - flag);
		if (ft_isspace(line[champ->i]))
			check_label_error(line, champ->i, champ->row);
		if (line[champ->i] == '#' || line[champ->i] == ';')
			return;
		if (line[champ->i] == LABEL_CHAR)
			champ->i = parse_label(line, champ->i, champ->row, champ); // LABEL
		else if (line[champ->i] == ' ')
		{
			// find occurence of *str in a table //check id no :
			check_op(ret, line + flag, champ->i - flag, champ, flag + 1); // INSTRUCTION
			return ;
		}
		champ->i++;
	}
}
