/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:04:14 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/08 16:11:09 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	init_asm(t_asm *champ)
{
	champ->i = 0;
	champ->row = 0;
	champ->pos = 0;
	champ->file_name = NULL;
	init_label_struct(champ);
	init_token_struct(champ);
}

void	init_label_struct(t_asm *champ)
{
	if (!(champ->head = ft_memalloc(sizeof(t_label))))
	{
		free(champ);
		exit(0);
	}
	champ->head->name = NULL;
	champ->head->pos = 0;
	champ->head->next = NULL;
}

void	init_token_struct(t_asm *champ)
{
	int	i;

	i = -1;
	if (!(champ->first = ft_memalloc(sizeof(t_token))))
	{
		free(champ->head);
		free(champ);
		exit(0);
	}
	champ->first->pos = 0;
	champ->first->op_code = 0;
	champ->first->encoded_byte = 0;
	champ->first->label = NULL;
	champ->first->line = NULL;
	while (++i < 3)
		champ->first->param[i] = NULL;
}
