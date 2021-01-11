/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:04:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/11 18:39:13 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void get_name_comment(char *line, t_asm *champ, int len)
{
	//printf("in get name comm [%s]\n", line);
	char *str;
	char **tab;

	if ((str = ft_strstr(line, "name")))
	{
		tab = ft_strsplit(line, '"');
		if (tab[1] == NULL)
		{
			// champ->header->prog_name = ; // set an array to null?
			return ;
		}
		if (ft_strlen(tab[1]) <= PROG_NAME_LENGTH)
			ft_memcpy(champ->header->prog_name, tab[1], ft_strlen(tab[1]));
		else
		{
			invalid_header(champ, 1);
		}
		ft_memdel((void**)tab);
	}
	else if ((str = ft_strstr(line, "comment")))
	{
		check_comment(len, str, line, champ);
	}
	else
	{
		ft_printf("Lexical error at [%d:%d]\n", champ->row, len  - (ft_strlen(line) - 1));
		exit(-1);
		// syntax_error(tab[0], )
	}
}

void check_comment(int len, char *str, char *line, t_asm *champ)
{
	int len2;
	int i;
	char **tab;
	len2 = len - ft_strlen(str);
	i = 7;
	while (str[i] != '"' && i < ft_strlen(str))
	{
		if (str[i] != '\t' && str[i] != ' ')
		{
			str = str_to_char(str + i, ' ');
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", champ->row, len2 + (i + 1), str);
			exit (-1);
		}
		i++;
	}
	if ( i == ft_strlen(str))
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n", champ->row, len + 1);
		exit(-1);
	}
	tab = ft_strsplit(line, '"');
	if (tab[1] == NULL)
	{
		// champ->header->comment = NULL;
		return ;
	}
	if (ft_strlen(tab[1]) <= COMMENT_LENGTH)
		ft_memcpy(champ->header->comment, tab[1], ft_strlen(tab[1]));
	else
	{
		invalid_header(champ, 2);
	}
	ft_memdel((void**)tab);
}

char *str_to_char(char *str, char c)
{
	int i;
	char *dst;

	i = 0;
	if (!(dst = ft_memalloc(sizeof(ft_strlen(str)))))
		return NULL;
	if (str)
	{
		while (*str == ' ')
			str += 1;
		while (str[i] != c)
		{
			dst[i] = str[i];
			i++;
		}
		return (dst);
	}
	return NULL;
}
