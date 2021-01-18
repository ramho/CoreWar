/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:00:12 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/18 15:24:35 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

char	*transfer_cmd_to_str(t_asm *champ, int fd)
{
	t_token *index;
	char	*code;
	int		pos;

	code = ft_strnew(champ->pos);
	index = champ->first;
	pos = 0;
	while (index)
	{
		code[pos] = g_op[index->op_code].code;
		pos += 1;
		if (g_op[index->op_code].args_types_code == true)
		{
			code[pos] = code_encoded_byte(index, index->op_code);
			pos += 1;
		}
		pos = code_params(code, pos, index, champ);
		index = index->next;
	}
	return (code);
}
