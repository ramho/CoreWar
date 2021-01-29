/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:04:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/29 17:20:26 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void get_name_comment(char *line, t_asm *champ, int len)
{
	// printf("in get name comm [%s]\n", line);
	char *str;
	char **tab;

	if ( ft_isspace(line[1]))
	{
		ft_printf("Lexical error at ");
		ft_printf("[%d:%d]\n", champ->row, len  - (ft_strlen(line) - 1));
		invalid_header(champ, 0, NULL);
	}
	else if ((str = ft_strstr(line, "name")))
	{
		tab = ft_strsplit(line, '"');
		if (tab[1] == NULL) // considering it is not an error
			return ;
		if (ft_strlen(tab[1]) <= PROG_NAME_LENGTH)
			ft_memcpy(champ->header->prog_name, tab[1], ft_strlen(tab[1]));
		else
		{
			ft_memdel((void**)tab);
			invalid_header(champ, 1, NULL);
		}
		ft_memdel((void**)tab);
	}
	else if ((str = ft_strstr(line, "comment")))
		check_comment(len, str, line, champ);
}

void check_comment(int len, char *str, char *line, t_asm *champ)
{
	int len2;
	int i;

	len2 = len - ft_strlen(str);
	i = 7;
	while (str[i] != '"' && i < ft_strlen(str))
	{
		if (str[i] != '\t' && str[i] != ' ')
		{
			str = str_to_char(str + i, ' ');
			ft_printf("Syntax error at token [TOKEN]");
			ft_printf(" [%03d:%03d] INSTRUCTION \"%s\"\n", champ->row, len2 + (i + 1), str)
			invalid_header(champ, 3, str);
		}
		i++;
	}
	if ( i == ft_strlen(str))
	{
		ft_strdel(&str);
		ft_printf("Syntax error at token [TOKEN]");
		ft_printf("[%03d:%03d] ENDLINE\n", champ->row, len + 1);
		invalid_header(champ, 0, NULL);
	}
	save_comment(line, champ);
}

void save_comment(char *line, t_asm *champ)
{
	char **tab;

	tab = ft_strsplit(line, '"');
	if (tab[1] == NULL) // a voir si pas une faute ?
	{
		// champ->header->comment = NULL;
		ft_memdel((void**)tab);
		return ;
	}
	if (ft_strlen(tab[1]) <= COMMENT_LENGTH)
	{
		ft_memcpy(champ->header->comment, tab[1], ft_strlen(tab[1]));
		ft_memdel((void**)tab);
	}
	else
	{
		ft_memdel((void**)tab);
		invalid_header(champ, 2, NULL);
	}
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
