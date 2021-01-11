/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/11 18:42:08 by rhoorntj         ###   ########.fr       */
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
	int start;
	char *line;
	char *buf;

	champ->row = 1;
	if ((fd = open(file, O_RDONLY)) <= 0)
		file_error(champ, file, 2);
	if (!(champ->header = ft_memalloc(sizeof(header_t))))
	{
		free(champ);
		exit(-1);
	}
	while ((get_next_line(fd, &line) > 0))
	{
		//check if comment before title like in car.s
		start = ft_pos_i(line, '#');
		line = ft_strsub(line, 0, start); // malloc free to check
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
	// printf("in PARSE_TOKEN line [%s]\n", line);
	// int i;
	int flag;
	char *ret;

	champ->i = 0; // can put in init asm.c
	champ->line = line;
	while (ft_isspace(line[champ->i]))
		champ->i++;
	// //printf(" i is [%c]\n", line[champ->i]);
	while (line && line[champ->i] != '\0' && line[champ->i] != '\n')
	{
		flag = champ->i;
		//printf("1\n");
		while (ft_strchr(LABEL_CHARS, line[champ->i]))
			champ->i++;
		ret = ft_strsub(line, flag, champ->i - flag);
		// printf("ret = [%s] row [%d]\n", ret, champ->row);
		// printf("2 c [%c]\n", line[champ->i]);
		if (ft_isspace(line[champ->i]))
		{
			while (ft_isspace(line[champ->i]))
				champ->i++;
			if (line[champ->i] == ':' && (!line[champ->i + 1] || ft_isspace(line[champ->i + 1])))
			{
				ft_printf("Lexical error at [%d:%d]\n", champ->row, champ->i + 1);
				exit(0);
			}
			check_op(ret, line + flag, champ->i - flag, champ, flag + 1); // INSTRUCTION

			return ;

			// check_label_error(line, champ->i, champ->row);
		}
		// //printf("3 c [%c]\n", line[champ->i]);
		if (line[champ->i] == '#' || line[champ->i] == ';')
			return;
		// //printf("4 c [%c]\n", line[champ->i]);
		if (line[champ->i] == LABEL_CHAR)
		{
			champ->i = parse_label(line, champ->i, champ->row, champ); // LABEL
		}
		else if (ft_isspace(line[champ->i]))
		{
			check_label_error(line, champ->i, champ->row);
			// find occurence of *str in a table //check id no :
			// printf("avant CHECK_OP dans PARSE_TOKEN line [%s] row [%d]\n", line, champ->row);
			// check_op(ret, line + flag, champ->i - flag, champ, flag + 1); // INSTRUCTION
			//
			// return ;
		}
		champ->i++;
	}
}
