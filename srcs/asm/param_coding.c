/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_coding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:25:24 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/02/08 17:05:52 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// [1] No such label li while attempting to dereference token [TOKEN][004:019] DIRECT_LABEL "%:li"

#include "../../includes/asm.h"

int	code_params(char *code, int pos, t_token *token, t_asm *champ)
{
	int	i;

	i = 0;

	while ( i < g_op[token->op_code].args_num)
	{
		if (token->param_type[i] == REG_CODE)
		{
			code[pos] = ft_atoi(token->param[i]);
			pos += 1;
		}
		else if (token->param_type[i] == IND_CODE || token->param_type[i] == DIR_CODE)
		{
			pos += add_dir_ind(code, token->param[i], token, i, pos,champ);
		}
		i++;
	}

	return (pos);
}

int	add_dir_ind(char *code, char *param, t_token *token, int i, int pos, t_asm *champ)
{
	// printf("in ADD ind or dir [%s]\n", param);
	int32_t	size;
	int32_t	value;

	if (token->param_type[i] == DIR_CODE)
		size = g_op[token->op_code].t_dir_size;
	else
		size = 2;

	if (ft_isalpha(param[0])) // label
	{
		//check if label exist otherwise error, [1]
		value = get_label_value(champ, token, param);
		int32_to_bytecode(code, pos, value , size);

	}
	else // int
	{
		int32_to_bytecode(code, pos, ft_atoi(param), size);
	}
	return (size);
}

// ERROR TO ADD -> No such label louuip while attempting to dereference token [TOKEN][005:004] INDIRECT_LABEL ":louuip"

int	get_label_value(t_asm *champ, t_token *token, char *param)
{
	// printf("in GET_LABEL_VALUE param [%s]\n", param);
	t_label	*index;

if ( champ->head->name)
{
	index = champ->head;
	while (index)
	{
		if (!ft_strcmp(param, index->name))
		{
			return (index->pos - token->pos);;
		}
		index = index->next;
	}
}
	// printf("ERROR label no have\n");
	ft_printf("No such label %s while attempting to dereference token [TOKEN][%03d:%03d]\n", param, 0, 0);
	exit (0);
}
