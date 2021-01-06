/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:10:21 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/06 16:11:48 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void parse_param(int op, char **tab)
{
	printf("  in PARSE_PARAM op [%s]\n", g_op[op].name);
	int i;
	int param;

	// printf(" DIR %s\n", ft_itoa_base(2, 2, 'm'));

	i = 0;
	while (i < g_op[op].args_num)
	{
		param = check_param(tab[i]);
		if (g_op[op].args_types[i] & param)
		{
			printf("param [%d][%d] is OK  ", i, param);
		}
		else
		{
			printf("ERROR - param[ %d - %s ][%d] doesn't match\n", i, tab[i],param);
			exit(0);
		}
		i++;
		printf("\n");
	}
}

int check_param(char *param)// better to use index or move pointer directly ???
{
	int i;

	i = 0;
	while(ft_isspace(param[i]))
		i++;
	if(param[i] == 'r')
	{
		return(T_REG);
	}
	else if (param[i] == '%')
	{
		return(T_DIR);
	}
	else if (ft_isdigit(param[i]))
	{
		return (T_IND);
	}
	return(1);
}
