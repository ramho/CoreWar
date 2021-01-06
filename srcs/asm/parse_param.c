/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:10:21 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/06 18:56:33 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void parse_param(int op, char **tab, t_asm *champ)
{
	printf("  in PARSE_PARAM op [%s]\n", g_op[op].name);
	int i;
	int param;
	char *type;

	i = 0;
	type = NULL;
	while (i < g_op[op].args_num)
	{
		param = check_param(ft_strtrim(tab[i]), champ);
		if (g_op[op].args_types[i] & param)
		{
			printf("param [%d][%d] is OK  ", i, param);
			//add to list
		}
		else if (param > 0)
		{
			if (param == 1)
				type = "register";
			if (param == 2)
				type = "direct";
			if (param == 4)
				type = "indirect";
			ft_printf("Invalid parameter %d type %s for instruction %s\n", i, type, g_op[op].name); // find way to indicate type
			exit(0);
		}
		i++;
		printf("\n");
	}
}

int check_param(char *param, t_asm *champ)// better to use index or move pointer directly ???
{
	printf("    in CHECK_PARAM [%s]\n", param);
	int i;
	int check;

	i = 0;
	if(param[i] == 'r')
	{
		check = ft_atoi(param + 1);
		printf("check is [%d]\n", check);
		if (check >= 1 && check <= 16)
			return(T_REG);
	}
	else if (param[i] == '%')
	{
		i++;
		if (param[i] == LABEL_CHAR)
		{
			printf("label dir\n");
		}
		elsewhere
		{
			printf("int dir\n")
		}
		return(T_DIR);
	}
	else if (ft_isdigit(param[i]) ||  param[i] == LABEL_CHAR)
	{
		if (param[i] == LABEL_CHAR)
		{
			printf("label ind\n")
		}
		else
		{
			printf("int ind\n");
		}
		return (T_IND);
	}
	ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", champ->row, ft_strstri(champ->line, param) + 1, param); // row and line
	exit(0);
	return(0);
}





// int check_dir()
// {
//
// }
//
// int check_ind()
// {
//
// }
//
// int check_reg()
// {
//
// }
