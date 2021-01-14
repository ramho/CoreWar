/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:25:03 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/14 16:50:30 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int check_dir(char *param, int param_i, t_asm *champ)
{
	//printf("in CHECK_DIR param [%s]\n", param);
	int i;

	i = 0;
	if (param[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, param[i]) && param[i])
			i++;
			champ->new_token->param[param_i] = param + 1;
			champ->new_token->param_type[param_i] = DIR_CODE;
			// //printf("\tDIR param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
			return (1);
	}
	else
	{
		i = ft_atoi(param); // problem if value is zero..
		if (i >= INT_MIN && i <= INT_MAX)
		{
			champ->new_token->param[param_i] = param;
			champ->new_token->param_type[param_i] = DIR_CODE;
			// //printf("\tDIR param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
			return (1);
		}
	}
	//error
	return (0);
}

int check_ind(char *param, int param_i, t_asm *champ)
{
	//printf("\tIND param [%s]\n", param);
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
			champ->new_token->param_type[param_i] = IND_CODE;
			//printf("\tIND param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
			return (1);
		}
	}
	else
	{
		i = ft_atoi(param);
		if (i >= INT_MIN && i <= INT_MAX)
		{
			champ->new_token->param[param_i] = param;
			champ->new_token->param_type[param_i] = IND_CODE;
			//printf("\tIND param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
			return (1);
		}
	}
	return (0);
}

int check_reg(char *param, int param_i, t_asm *champ)
{
	// //printf("\tREG param [%s]\n", param);
	int check;

	check = ft_atoi(param);
	if (check >= 1 && check <= 16)
	{
		champ->new_token->param[param_i] = param;
		champ->new_token->param_type[param_i] = REG_CODE;
		// //printf("\tREG param [%d] [%s][%d]\n", param_i, champ->new_token->param[param_i],champ->new_token->param_type[param_i]);
		return (1);
	}
	//error
	return (0);
}
