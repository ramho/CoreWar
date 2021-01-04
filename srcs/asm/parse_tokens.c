/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/12/17 18:14:56 by rhoorntj         ###   ########.fr       */
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
			get_opcode(line, champ, row);
		free(line);
		row++;
	}
}

void get_opcode(char *line, t_asm *champ, int row)
{
	int i;
	int label_flag;
	 char *tmp = malloc(sizeof(char) * 5);

	printf("line[%d] in opcode is [%s]\n", row, line);
	i = 0;
	label_flag = 0;
	while (ft_isspace(line[i]))
		i++;
	while(line && line[i] != '\0')
	{
		printf("\ti:[%d] - [%c] ",i, line[i]);
		while (ft_strchr(LABEL_CHARS, line[i]))
		{
			tmp[i] = line[i];
			i++;
		}
		printf("tmp [%s] i=[%c]\n", tmp, line[i]);
		printf("op [%s]\n", g_op[1].name);
		// if (tmp == )
		// {
		// 	free(tmp);
			// parse_op(line);
		// }
		if (line[i] == LABEL_CHAR && label_flag == 0)
			{
					i = parse_label(line, i, row);
					label_flag = 1;
			}
			// else
			// {
			// 	printf("error\n");
			// }
		i++;

	}
	printf("\n");
	// if
}

int parse_label(char *line, int i, int row)
{
	char *label_name;

	label_name = malloc(sizeof(char*) * i);
	ft_strncpy(label_name, line, i);
	// printf("\n\tlabel name is [%s]\n", label_name);
	// printf("\t1- i [%c]\n", line[i]);
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	printf("\t2- i[%d]- c:[%c]\n", i,line[i]);
	return (i);
}

void parse_op(char *line)
{
	printf("in parse op [%s]\n", line);
}

void parse_param()
{

}
