/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:14:27 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/06 16:16:37 by rhoorntj         ###   ########.fr       */
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

int parse_label(char *line, int i, int row)
{
	printf(" in PARSE_LABEL [%s] row %d\n", line, row);
	char *label_name;

	label_name = malloc(sizeof(char*) * i);
	ft_strncpy(label_name, line, i);
	i += 1;
	while (ft_isspace(line[i]))
	i++;
	return (i - 1); // to cancel out the i++ in get_opcode
}
