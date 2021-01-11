/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:19:25 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/11 18:42:41 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"


void check_op(char *name, char *line, int size_op, t_asm *champ, int column)
 {
	 // printf("in CHECK_OP\n");
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
 		j++;
 	if (j != g_op[op].args_num)
 	{
 		ft_printf("Invalid parameter count for instruction %s\n", ret);
 		exit(0);
 	}
	if (!(champ->new_token = ft_memalloc(sizeof(t_token))))
	{
		//printf("malloc_error in parse op\n");
		exit(0);
	}
	champ->new_token->op_code = op;
	if( champ->head->flag == 1)
	{
		champ->new_token->label = champ->head->name; // need to add a flag so only label if there is one
		champ->head->flag = 0;
	}
	champ->new_token->pos =	champ->pos;
	champ->new_token->line = ft_strdup(line);
	champ->new_token->column = column;
	// //printf("line [%s] i [%d]\n",champ->new_token->line, champ->new_token->column );
 	parse_param(op, tab, champ);

 	return (1);
 }

void	calc_new_pos(t_token *token, t_asm *champ)
{
	int byte;
	int i;

	byte = 1;
	i = 0;
	if (g_op[token->op_code].args_types_code)
		byte += 1;
	while (i < g_op[token->op_code].args_num)
	{
		if (token->param_type[i] == T_REG)
		{
			byte += 1;
			// //printf("\tREG  byte = [%d]\n", byte);
		}
		else if (token->param_type[i] == T_IND)
		{
			byte += 2;
			// //printf("\tIND byte = [%d]\n", byte);
		}
		else if (token->param_type[i] == T_DIR)
		{
			byte += g_op[token->op_code].t_dir_size;
			// //printf("\tDIR size [%d]\n", g_op[token->op_code].t_dir_size);
			// //printf("\tDIR byte = [%d]\n", byte);
		}
		i++;
	}
	champ->pos += byte;
	// //printf("*** size = [%d]\n", champ->pos);
}
