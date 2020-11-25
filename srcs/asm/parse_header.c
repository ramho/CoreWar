/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:04:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/11/25 18:26:01 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void get_name_comment(char *line, t_asm *champ, int row, int len)
{
	// printf("in get name comm [%s]\n", line);
	char *str;
	char **tab;

	champ->header = ft_memalloc(sizeof(header_t));
	if ((str = ft_strstr(line, "name")))
	{
		tab = ft_strsplit(line, '"');
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
    check_comment(len,row, str, line, champ);
	}
	else
	{
		ft_printf("Lexical error at [%d:%d]\n", row, len  - (ft_strlen(line) - 1));
		// syntax_error(tab[0], )
	}
}

void check_comment(int len, int row, char *str, char *line, t_asm *champ)
{
  int len2;
  int i;
  char **tab;

  len2 = len - ft_strlen(str);
  i = 7;
  while (str[i] != '"')
  {
    if (str[i] != ' ' || str[i] != '"')
    {
      // invalid_header(champ, 3);
      str = str_to_char(str + i, ' ');
      ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", row, len2 + (i + 1), str);
      exit (-1);
    }
    i++;
  }
  tab = ft_strsplit(line, '"');
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
