/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:00:12 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/14 12:59:41 by rhoorntj         ###   ########.fr       */
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
			printf("here\n");
			code[i] = code_encoded_byte(index, index->op_code);
			i += 1;
		}
		// code_params();
		index = index->next;
	}
	write(fd, code, champ->pos);

}

static int32_t	ft_llongmax(unsigned long long int nb, int sign)
{
	if (nb > 9223372036854775807)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	else
		return (nb * sign);
}

int32_t			ft_atoi32(const char *str)
{
	int						i;
	unsigned long long int	result;
	int						sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0')
	{
		while ((str[i] > 0 && str[i] <= 26) || (str[i] > 27 && str[i] < 33))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = sign * (-1);
			i++;
		}
		while (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		{
			result = result * 10 + str[i] - '0';
			i++;
		}
		return ((int32_t)ft_llongmax(result, sign));
	}
	return ((int32_t)ft_llongmax(result, sign));
}

// int32_to_bytecode(parser->code, parser->pos, (int16_t)ft_atoi32(&current->content[start]),size);
