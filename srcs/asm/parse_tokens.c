/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/04 16:20:54 by rhoorntj         ###   ########.fr       */
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
		// printf(" 1 line %d is [%s][%p]\n", row, line, line);
		if ((buf = ft_strchr(line, '.')))
			get_name_comment(buf, champ, row, ft_strlen(line));
		else
		{
			// printf(" 2 line %d is [%s]\n", row, line);
			get_opcode(line, champ, row);
		}
		// printf(" 3 line %d is [%s]\n", row, line);
		free(line);
		// printf("line freed of GNL in get_file\n\n");
		row++;
	}
	// printf("leaving get file \n");
}

void get_opcode(char *line, t_asm *champ, int row)
{
	int i;
	int flag;
	int label_flag;
	char *ret;
	int j;

	 // char *tmp = malloc(sizeof(char) * 5);

	printf("IN OPCODE line[%d] in opcode is [%s]\n", row, line);
	i = 0;
	label_flag = 0;
	while (ft_isspace(line[i]))
		i++;
	// printf("line after whitespace [%s]\n", line + i);
	while(line && line[i] != '\0' && line[i] != '\n')
	{
		flag = i;
		while (ft_strchr(LABEL_CHARS, line[i]))
		{
			i++;
		}
		ret = ft_strsub(line, flag, i - flag);
		// printf("RET is [%s] line[i] = [%c]\n", ret, line[i]);
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
		// printf("END i [%d] line[i] [%c]\n", i, line[i]);

	}
	// printf("OUT Of GET OPCODE\n\n");
	// if
}

int parse_label(char *line, int i, int row)
{
	printf("\tin parse_label [%s]\n", line);
	char *label_name;

	label_name = malloc(sizeof(char*) * i);
	ft_strncpy(label_name, line, i);
	// printf("\n\tlabel name is [%s]\n", label_name);
	// printf("\t1- i [%c]\n", line[i]);
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	// printf("\t\t PARSE_LABEL i[%d]- c:[%c]\n", i,line[i]);
	return (i - 1); // to cancel out the i++ in get_opcode
}

int parse_op(char *line, int i, int op)
{
	char **tab;

	printf("\tin parse op [%s], [%s]\n", line, line + i);
	tab = ft_strsplit(line + i, SEPARATOR_CHAR);
	int j = 0;
	while (tab[j] != NULL)
	{
		printf("tab[%d] -->[%s]\n", j, tab[j]);
		j++;
	}
	printf("j [%d] VS op [%d]\n", j, g_op[op].args_num);
	if (j != g_op[op].args_num)
	{
		printf("ERROR\n");
		exit(0);
	}
	return (1);
}
//
// void parse_param()
// {
//
// }
