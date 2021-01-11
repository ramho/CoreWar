/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:14:27 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/11 18:13:47 by rhoorntj         ###   ########.fr       */
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
	//printf("in PARSE_LABEL [%s] row %d\n", line, row);
	t_label *new;

	if (!(new = ft_memalloc(sizeof(t_label))))
	{
		//printf("malloc error in parse label\n");
		exit(0);
	}
	if (!(new->name = ft_strsub(line, 0, i)))
	{
		//printf("malloc error in parse label with strsub\n");
		exit(0);
	}
	new->pos = champ->pos;
	add_label_link(new, champ);
	// //printf("OUT OF IT ALL head name [%s]\n", champ->head->name);
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	return (i - 1); // to cancel out the i++ in get_opcode
}
