/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:30:41 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/11/25 18:06:42 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

// void invalid_param()
// {
// 	ft_printf("Invalid parameter %d type %s for instruction %s\n", param_nb, type, op);
// 	//free everything from before
// 	exit(-1);
// }
//
// void syntax_error()
// {
// 	ft_printf("Syntax error at tokem [TOKEN][:]");
// }

void invalid_header(t_asm *champ, int error)
{
	if (error == 1)
	{
		ft_printf("Champion name too long (Max length 128)\n");
		//free tab and line in champ
	}
	if (error == 2)
	{
		ft_printf("Champion comment too long (Max length 2048)\n");
		//free tab and line in champ
	}
	// if (error = 3)
	// {
	// 	ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n",
	// 	 	row, len2 + (i + 1), str + i);
	// 		//free tab and line in champ
	// }
	exit (-1);
}

void file_error(t_asm *champ, char *file_name, int error)
{
	if (error == 1)
		ft_printf("Can't read source file %s\n", file_name);
	if (error == 2)
	{
		ft_printf("Couldn't open file %s\n", file_name);
		ft_strdel(&champ->file_name);
	}
	free(champ);
	exit(-1);
}

void malloc_error(t_asm *champ, char *file)
{
	ft_printf("Malloc error in %s\n", file);
	free(champ);
	exit (-1);
}
