/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:14:27 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/07 18:38:11 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"


void check_label_error(char *line, int index, int row)
{
	int i;

	i = index;
	while (ft_isspace(line[i]))
	{
		i++;
	}
	if (line[i] == ':')
	{
		ft_printf("Lexical error at [%d:%d]\n", row, i + 1);
		exit(0);
	}
}

int parse_label(char *line, int i, int row, t_asm *champ)
{
	printf(" in PARSE_LABEL [%s] row %d\n", line, row);
	t_label new;

	new.name = malloc(sizeof(char*) * i);
	ft_strncpy(new.name, line, i);
	new.pos = champ->pos;
	add_label_link(new, champ->head);
	i += 1;
	while (ft_isspace(line[i]))
	i++;
	return (i - 1); // to cancel out the i++ in get_opcode
}
