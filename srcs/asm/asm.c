/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:34 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/12 18:12:25 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_asm *check_arg(int ac, t_asm *champ)
{
	if (ac < 2)
	{
		ft_printf("Usage: ./asm [-*****] <sourcefile.s>\n");
		return (0);
	}
	if (!(champ = ft_memalloc(sizeof(t_asm))))
		return (0);
	return (champ);
}

int	main(int ac, char **av)
{
	t_asm *champ;
	// char *line;
	int fd;

 	champ = NULL;
	if (!(champ = check_arg(ac, champ)))
		return (-1);
	init_asm(champ);
	if (valid_file(champ,  av[ac - 1]))
		get_file(av[ac - 1], champ);
	fd = create_cor_file(champ); // should go after
	transfer_cmd_to_str(champ, fd);
	// fd = create_cor_file(champ);
	// encode(champ, fd);
	// FOR DEBUGING ONLY
		t_label *index;
			index = champ->head;
			while (index)
			{
				printf("name [%s] post[%d]\n", index->name, index->pos);
				index = index->next;
			}

		t_token *index2;
		index2 = champ->first;
		while (index2)
		{
			printf("\tline [%s] name [%s] label [%s]\n", index2->line, g_op[index2->op_code].name, index2->label);
			index2 = index2->next;
		}
	// END
	return (0);
}
