/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_coding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:25:24 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/16 16:37:00 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int code_params(char *code, int pos, t_token *token, t_asm *champ)
{
	int i;
	// int8_t pos;

	i = 0;
	// pos = 0;

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

int add_dir_ind(char *code, char *param, t_token *token, int i, int pos, t_asm *champ)
{
	printf("in ADD ind or dir [%s]\n", param);
	int32_t size;
	int32_t value;

	if (token->param_type[i] == DIR_CODE)
		size = g_op[token->op_code].t_dir_size;
	else
		size = 2;

	if (ft_isalpha(param[0])) // label
	{
		// printf("\tis label\n");
		value = get_label_value(champ, token, param);
		printf("  label pos/value [%d]\n", value);
		int32_to_bytecode(code, pos, value , size);

	}
	else // int
	{
		int32_to_bytecode(code, pos, ft_atoi(param), size);
		// printf("\tis int\n");
	}
	return (size);
}

int	get_label_value(t_asm *champ, t_token *token, char *param)
{
	t_label *index;

	index = champ->head;
	while (index)
	{
		printf("if strcmp [%s] - [%s]\n", param, index->name);
		if (!ft_strcmp(param, index->name))
		{
			printf(" [%d] - [%d] = [%d]\n", index->pos, token->pos, index->pos - token->pos);
			return (index->pos - token->pos);;
		}
		index = index->next;
	}
	return (-1);
}
