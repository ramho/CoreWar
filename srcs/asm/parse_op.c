/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:19:25 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/08 14:14:55 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"


void check_op(char *ret, char *line, int op_name, t_asm *champ, int column)
 {
	 // printf("in CHECK_OP\n");
	 // printf("   ret [%s] line [%s] row %d\n",ret, line, row);
	 int j;

	 j = 0;
	 while (j < 16)
	 {
		if (ft_strcmp(ret, g_op[j].name) == 0)
		{
			if (parse_op(ret,line, op_name, j, champ))
				return ;
		}
		j++;
	}
	ft_printf("Invalid instruction at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", champ->row, column, ret);
	exit (-1);
 }

 int parse_op(char *ret, char *line, int i, int op, t_asm *champ)
 {
 	// printf(" in PARSE_OP row %d\n", champ->row);
 	int j;
 	char **tab;

 	tab = ft_strsplit(line + i, SEPARATOR_CHAR);
 	j = 0;
 	while (tab[j] != NULL)
 		j++;
 	if (j != g_op[op].args_num)
 	{
 		ft_printf("Invalid parameter count for instruction %s\n", ret);
 		exit(0);
 	}
 	parse_param(op, tab, champ);
 	return (1);
 }
