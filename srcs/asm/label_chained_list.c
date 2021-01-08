/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_chained_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:05:40 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/08 14:54:57 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void add_label_link(t_label *new, t_asm *champ)
{
	t_label *index;
	if (champ->head->name == NULL)
	{
		champ->head = init_link(new, champ->head);
	}
	else
	{
		new->next = champ->head;
		champ->head = new;
	}

// FOR DEBUGING ONLY
	// index = champ->head;
	// while (index)
	// {
	// 	index = index->next;
	// }
// END

}


t_label *init_link(t_label *new, t_label *head)
{
	head->name = new->name;
	head->pos = new->pos;
	head->next = NULL;
	return(head);
}
