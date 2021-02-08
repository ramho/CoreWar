/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:19:25 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/02/08 17:06:37 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"


void check_op(char *name, char *line, int size_op, t_asm *champ, int column)
 {
	 printf("in CHECK_OP line [%s]\n", line);
	 // printf("   name [%s] line [%s] column [%d]\n",name, line, column);
	 int j;

	 j = 0;
	 while (j < 16)
	 {
		if (ft_strcmp(name, g_op[j].name) == 0)
		{
			if (parse_op(name,line, size_op, j, champ, column))
			{
				// add to chained list
				add_op_link(champ->new_token, champ);
				// calculate position
				calc_new_pos(champ->new_token, champ);
				// calculate encoded byte
				printf(" 3 - ADD of NEW TOKEN [%p]\n",champ->new_token  );
				free(champ->new_token);
				printf("FREE\n");
				return ;
			}
		}
		j++;
	}
	ft_printf("Invalid instruction at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", champ->row, column, name);
	exit (-1);
 }

 int parse_op(char *ret, char *line, int i, int op, t_asm *champ, int column)
 {
 	//printf(" in PARSE_OP row %d\n", champ->row);
 	int j;
 	char **tab;

 	tab = ft_strsplit(line + i, SEPARATOR_CHAR);
 	j = 0;
 	while (tab[j] != NULL)
	{
		printf("op is [%s]\n", tab[j]);
 		j++;
	}
 	if (j != g_op[op].args_num)
 	{
		ft_strdel(&line);
		ft_memdel((void**)tab);
		invalid_op(champ, 2, ret);
 	}
	printf(" 1 - ADD of NEW TOKEN [%p]\n",champ->new_token  );

	if (!(champ->new_token = ft_memalloc(sizeof(t_token))))
	{
		ft_strdel(&line);
		ft_memdel((void**)tab);
		invalid_op(champ, 0, ret);
	}
	printf(" 2 - ADD of NEW TOKEN [%p]\n",champ->new_token  );
	champ->new_token->op_code = op;
	if( champ->head->flag == 1)
	{
		champ->new_token->label = champ->head->name; // need to add a flag so only label if there is one
		champ->head->flag = 0;
	}
	champ->new_token->pos =	champ->pos;
	champ->new_token->line = ft_strdup(line);
	champ->new_token->column = column;
	// ft_strdel(&line); // sefgault
	ft_strdel(&ret);
 	parse_param(op, tab, champ);

 	return (1);
 }

/*
** Byte starts at 1 for the op name.
*/
void	calc_new_pos(t_token *token, t_asm *champ)
{
	// printf("in CALC_NEW_POS name [%s]\n", g_op[token->op_code].name);
	int byte;
	int i;

	byte = 1;
	i = 0;
	if (g_op[token->op_code].args_types_code)
		byte += 1;
	while (i < g_op[token->op_code].args_num)
	{
		if (token->param_type[i] == REG_CODE)
		{
			byte += 1;
			// printf("\tREG\n");
		}
		else if (token->param_type[i] == IND_CODE)
		{
			byte += 2;
			// printf("\tIND\n");
		}
		else if (token->param_type[i] == DIR_CODE)
		{
			byte += g_op[token->op_code].t_dir_size;
			// printf("\tDIR\n");
		}
		i++;
	}
	champ->pos += byte;
	// printf("*** size = [%d] op size [%d]\n", champ->pos, byte);
}
