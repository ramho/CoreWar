/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:00:12 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/13 14:16:07 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	transfer_cmd_to_str(t_asm *champ, int fd)
{
	t_token *index;
	char *code;
	int i;

	uint8_t p = 68;

	printf("p %c\n", p);

	code = ft_strnew(champ->pos);
	index = champ->first;
	i = 0;
	while (index)
	{
		code[i] = g_op[index->op_code].code;
		i += 1;
		if (g_op[index->op_code].args_types_code == true)
		{
			int32_to_bytecode(code, 1, (uint8_t)p, 1);
			// ft_memcpy(&code[1], &p , 1);
			i += 1;
		}
		index = index->next;
	}
	write(fd, code, champ->pos);

}


// int32_to_bytecode(parser->code, parser->pos, (int16_t)ft_atoi32(&current->content[start]),size);
