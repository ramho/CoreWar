/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/04 17:03:35 by rhoorntj         ###   ########.fr       */
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
			get_opcode(line, champ, row);
		}
		free(line);
		row++;
	}
}

void get_opcode(char *line, t_asm *champ, int row)
{
	int i;
	int j;
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
		if (line[i] == LABEL_CHAR)
		{
			i = parse_label(line, i, row);
			free(ret);
		}
		else if (line[i] == ' ')// find occurence of *str in a table //check id no :
		 {
			 j = 0;
			 while ( j < 16)
			 {
				 if (ft_strcmp(ret, g_op[j].name) == 0)
			 	{
					if (parse_op(line + flag, i - flag, j))
						return ;
		 		}
				j++;
			}
		}
		i++;
	}
}

int parse_label(char *line, int i, int row)
{
	printf("\tin parse_label [%s]\n", line);
	char *label_name;

	label_name = malloc(sizeof(char*) * i);
	ft_strncpy(label_name, line, i);
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	return (i - 1); // to cancel out the i++ in get_opcode
}

int parse_op(char *line, int i, int op)
{
	int j;
	char **tab;

	tab = ft_strsplit(line + i, SEPARATOR_CHAR);
	j = 0;
	while (tab[j] != NULL)
	{
		j++;
	}
	if (j != g_op[op].args_num)
	{
		printf("ERROR\n");
		exit(0);
	}
	parse_param(tab);
	return (1);
}

void parse_param(char **tab)
{

}
