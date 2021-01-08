/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_chained_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:48:52 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/08 17:18:20 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

// initiliase a tab of 3 to null
//
// init new_link

void add_op_link(t_token *new, t_asm *champ)
{
	t_token *index;
	if (champ->first->line == NULL)
	{
		champ->first = init_op_link(new, champ->first);
	}
	// else
	// {
	// 	new->next = champ->head;
	// 	champ->head = new;
	// }

	// FOR DEBUGING ONLY
	// index = champ->head;
	// while (index)
	// {
	// 	index = index->next;
	// }
	// END

}


t_token *init_op_link(t_token *new, t_token *first)
{
	int i;

	i = -1;
	first->pos = new->pos;
	first->op_code = new->op_code;

	// first->encoded_byte = new; // now or later ?

	if(!(first->label = ft_strdup(new->label)))
	{
		ft_printf("strdup 1 errror in init_op_link\n");
		exit(0);
	}
	if(!(first->line = ft_strdup(new->line)))
	{
		ft_printf("strdup 2 errror in init_op_link\n");
		exit(0);
	}
	first->column = new->column;
	while (++i < 3)
	{
		if(!(first->param[i] = ft_strdup(new->param[i])))
		{
			ft_printf("strdup 3 [i] errror in init_op_link\n", i );
			exit(0);
		}
	}
	return(first);
}
