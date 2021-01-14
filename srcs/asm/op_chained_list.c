/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_chained_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:48:52 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/14 16:48:53 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

// initiliase a tab of 3 to null
//
// init new_link

void add_op_link(t_token *new, t_asm *champ)
{
	//printf("in ADD_OP_LINK\n");
	// //printf("pos [%d]\top_code[%d]\tlabel[%s]\tline[%s]\n", new->pos, new->op_code, new->label, new->line);
	t_token *index;

	if (champ->first->line == NULL)
	{
		champ->first = init_op_link(new, champ->first);
		// //printf("out in INIT OP LINK\n");
	}
	else
	{
		index = champ->first;
		while (index->next != NULL)
		{
			// //printf("\tINDEX [%s]\n", index->line);
			index = index->next;
		}
		index->next = new;
	}

	// FOR DEBUGING ONLY
	// index = champ->first;
	// while (index)
	// {
	// 	//printf("\t\tchamp op [%d] [%s] label [%s]\n", index->op_code, index->line, index->label);
	// 	index = index->next;
	// }
	// END

}


t_token *init_op_link(t_token *new, t_token *first)
{
	//printf("in INIT_OP_LINK\n");
	int i;

	i = -1;
	first->pos = new->pos;
	first->op_code = new->op_code;
	// first->encoded_byte = new; // now or later ?
	//printf("1\n");
	if (new->label)
	{
		if(!(first->label = ft_strdup(new->label)))
		{
			ft_printf("strdup 1 errror in init_op_link\n");
			exit(0);
		}
	}
	//printf("2\n");
	if(!(first->line = ft_strdup(new->line)))
	{
		ft_printf("strdup 2 errror in init_op_link\n");
		exit(0);
	}
	first->column = new->column;
	//printf("3\n");
	while (++i < g_op[new->op_code].args_num)
	{
		//printf("i [%d]\n", i);
		if(!(first->param[i] = ft_strdup(new->param[i])))
		{
			ft_printf("strdup 3 [i] errror in init_op_link\n", i );
			exit(0);
		}
		first->param_type[i] = new->param_type[i];
	}
	//printf("4\n");
	return(first);
}
