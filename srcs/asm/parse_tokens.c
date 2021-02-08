/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/02/08 14:54:59 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

// Syntax error at token
// Lexical error at [3:1}
// Syntax error at token [TOKEN][002:002] INSTRUCTION "ld" lde.s

// Invalid parameter [2(0-2)] type [register] for instruction [ld]

void parse_token(char *line, t_asm *champ)
{
	// printf("in PARSE_TOKEN line [%s]\n", line);
	int flag;
	char *ret;

	champ->i = 0; // can put in init asm.c
	champ->line = line;
	while (ft_isspace(line[champ->i]))
		champ->i++;
	while (line && line[champ->i] != '\0' && line[champ->i] != '\n')
	{
		flag = champ->i;
		while (ft_strchr(LABEL_CHARS, line[champ->i]))
			champ->i++;
		if (!(ret = ft_strsub(line, flag, champ->i - flag)))
		{
			ft_strdel(&line);
			invalid_op(champ, 0, NULL);
		}
		// ft_printf("1 - line[champ->i] = [%c]\n", line[champ->i]);
		if (ft_isspace(line[champ->i]))
		{
			while (ft_isspace(line[champ->i]))
				champ->i++;
			// ft_printf("2 - line[champ->i] = [%c] +1 = [%c]\n", line[champ->i], line[champ->i + 1] );
			if (line[champ->i] == ':' && (!line[champ->i + 1] || ft_isspace(line[champ->i + 1])))
			{
				ft_printf("Lexical error at [%d:%d]\n", champ->row, champ->i + 1);
				exit(0);
			}
			check_op(ret, line + flag, champ->i - flag, champ, flag + 1); // INSTRUCTION
			return ;
		}
		if (line[champ->i] == '#' || line[champ->i] == ';')
			return;
		if (line[champ->i] == LABEL_CHAR)
		{
			champ->i = parse_label(line, champ->i, champ->row, champ); // LABEL
		}
		else if (ft_isspace(line[champ->i]))
		{
			check_label_error(line, champ->i, champ->row);
			// find occurence of *str in a table //check id no :
		}
		champ->i++;
	}
}
