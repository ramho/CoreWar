/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:10:21 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/02/08 17:16:24 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void parse_param(int op, char **tab, t_asm *champ)
{
	// printf("in PARSE_PARAM op [%s]\n", g_op[op].name);
	int i;
	int param;
	char *type;

	i = -1;
	type = NULL;
	while (++i < g_op[op].args_num)
	{
		param = check_param(ft_strtrim(tab[i]), champ, i);
		// printf(" param [%s]\n", tab[i]);
		if (!(g_op[op].args_types[i] & param) && param > 0)
		{
			ft_memdel((void**)tab);
			invalid_param(champ, param, i, op);
		}
	}
}

int check_param(char *param, t_asm *champ, int param_i)// better to use index or move pointer directly ???
{
	// printf("    in CHECK_PARAM [%s] c[%c]\n", param, param[0]);
	int i;
	// int check;
	int ret = 0;

	i = 0;
	if (param[i] == 'r') // reg
	{
		// printf("in REG \n");
		if ((ret = check_reg(param + 1, param_i, champ)))
			return(T_REG);
	}
	else if (param[i] == DIRECT_CHAR) // dir
	{
		// printf("in DIR \n");
		// //printf(" in DIRECt the char is [%c]\n", param[i]);
		i++;
		if ((check_dir(param + i, param_i, champ)))
			return (T_DIR);
	}
	else if (ft_isdigit(param[i]) || param[i] == LABEL_CHAR || param[i] == '-') // ind
	{
		// printf("in IND \n");
		if ((check_ind(param , param_i, champ)))
			return (T_IND);
	}
	ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", champ->row, ft_strstri(champ->line, param) + 1, param); // row and line
	exit(0);
	return (0);
}
