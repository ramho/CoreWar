/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:34 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/18 15:41:09 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_asm	*check_arg(int ac, t_asm *champ)
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

int		main(int ac, char **av)
{
	int		fd;
	char	*code;
	t_asm	*champ;

	fd = 0;
	champ = NULL;
	if (!(champ = check_arg(ac, champ)))
		return (-1);
	init_asm(champ);
	if (valid_file(champ, av[ac - 1]))
		get_file(av[ac - 1], champ, fd);
	code = transfer_cmd_to_str(champ, fd);
	fd = create_cor_file(champ);
	encode(champ, fd, code);
	return (0);
}
