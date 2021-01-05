/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:49 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/05 17:47:19 by rhoorntj         ###   ########.fr       */
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
		if (line[i] == '#' || line[i] == ';')
		{
			return;
		}
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
	printf(" in PARSE_LABEL [%s]\n", line);
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
	printf(" in PARSE_OP\n");
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
	parse_param(op, tab);
	return (1);
}

void parse_param(int op, char **tab)
{
	printf("  in PARSE_PARAM op [%s]\n", g_op[op].name);
	int i;
	int param;

	// printf(" DIR %s\n", ft_itoa_base(2, 2, 'm'));

	i = 0;
	while (i < g_op[op].args_num)
	{
		param = check_param(tab[i]);
		if (g_op[op].args_types[i] & param)
		{
			printf("param [%d][%d] is OK  ", i, param);
		}
		else
		{
			printf("ERROR - param[ %d - %s ][%d] doesn't match\n", i, tab[i],param);
			exit(0);
		}
		i++;
		printf("\n");
	}
}

int check_param(char *param)// better to use index or move pointer directly ???
{
	int i;

	i = 0;
	while(ft_isspace(param[i]))
		i++;
	if(param[i] == 'r')
	{
		return(T_REG);
	}
	else if (param[i] == '%')
	{
		return(T_DIR);
	}
	else if (ft_isdigit(param[i]))
	{
		return (T_IND);
	}
	return(1);
}
