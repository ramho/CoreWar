/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:10:21 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/08 18:55:14 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void parse_param(int op, char **tab, t_asm *champ)
{
	printf("in PARSE_PARAM op [%s]\n", g_op[op].name);
	int i;
	int param;
	char *type;

	i = -1;
	type = NULL;
	while (++i < g_op[op].args_num)
	{
		// printf("i [%d] < [%d]\n", i ,g_op[op].args_num );
		param = check_param(ft_strtrim(tab[i]), champ, i);
		// printf(" param [%d]\n", param);
		if (!(g_op[op].args_types[i] & param) && param > 0)
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
		// printf("PARAM [%d] OK\n", param);
	}
}

int check_param(char *param, t_asm *champ, int param_i)// better to use index or move pointer directly ???
{
	// printf("    in CHECK_PARAM [%s] c[%c]\n", param, param[0]);
	int i;
	int check;
	int ret = 0;

	i = 0;
	if (param[i] == 'r') // reg
	{
		if ((ret = check_reg(param + 1, param_i, champ)))
			return(T_REG);
	}
	else if (param[i] == DIRECT_CHAR) // dir
	{
		// printf(" in DIRECt the char is [%c]\n", param[i]);
		i++;
		if ((check_dir(param + i, param_i, champ)))
			return (T_DIR);
	}
	else if (ft_isdigit(param[i]) ||  param[i] == LABEL_CHAR) // ind
	{
		if ((check_ind(param , param_i, champ)))
			return (T_IND);
	}
	ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", champ->row, ft_strstri(champ->line, param) + 1, param); // row and line
	exit(0);
	return (0);
}

int check_dir(char *param, int param_i, t_asm *champ)
{
	// printf("\tDIR param [%s]\n", param);
	int i;

	i = 0;
	if (param[i + 1] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, param[i]) && param[i])
			i++;
		if (i == ft_strlen(param))
		{

			champ->new_token->param[param_i] = param + 1;
			champ->new_token->param_type[param_i] = T_DIR;
			printf("\tDIR param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
			return (1);
		}
	}
	else
	{
		i = ft_atoi(param);
		if (i >= INT_MIN && i <= INT_MAX)
		{
			champ->new_token->param[param_i] = param;
			champ->new_token->param_type[param_i] = T_DIR;
			printf("\tDIR param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
			return (1);
		}
	}
	//error
	return (0);
}

int check_ind(char *param, int param_i, t_asm *champ)
{
	// printf("\tIND param [%s]\n", param);
	int i;

	i = 0;
	if (param[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, param[i]) && param[i])
			i++;
		if (i == ft_strlen(param))
		{
			champ->new_token->param[param_i] = param + 1;
			champ->new_token->param_type[param_i] = T_IND;
			printf("\tIND param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
			return (1);
		}
	}
	else
	{
		i = ft_atoi(param);
		if (i >= INT_MIN && i <= INT_MAX)
		{
			champ->new_token->param[param_i] = param;
			champ->new_token->param_type[param_i] = T_IND;
			printf("\tIND param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
			return (1);
		}
	}
	return (0);
}

int check_reg(char *param, int param_i, t_asm *champ)
{
	// printf("\tREG param [%s]\n", param);
	int check;

	check = ft_atoi(param);
	if (check >= 1 && check <= 16)
	{
		champ->new_token->param[param_i] = param;
		champ->new_token->param_type[param_i] = T_REG;
		printf("\tREG param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
		return (1);
	}
	//error
	return (0);
}
