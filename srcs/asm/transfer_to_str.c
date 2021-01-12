/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:00:12 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/12 18:24:03 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	transfer_cmd_to_str(t_asm *champ, int fd)
{
	t_token *index;
	char *code;
	int i;

	code = ft_strnew(champ->pos);
	index = champ->first;
	i = 0;
	while (index)
	{
		code[i] = g_op[index->op_code].code;
		i += 1;
		if (g_op[index->op_code].args_types_code == true)
		{
			code[i] = (uint8_t)68 & 0XFF;
			i += 1;
		}
		index = index->next;
	}
	write(fd, code, champ->pos);

}
