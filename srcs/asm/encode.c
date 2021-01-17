/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:56:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/01/17 13:09:25 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	int32_to_bytecode(char *data, int32_t pos, int32_t value, size_t size)
{
	int8_t	i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

void	encode(t_asm *champ, int fd, char *code)
{
	char	*encoding;
	int		pos;
	int		len;

	pos = 0;
	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + champ->pos; // check champ->pos is total size
	encoding = ft_strnew(len);
	int32_to_bytecode(encoding, pos, COREWAR_EXEC_MAGIC, 4); // MAGIC NUMBER
	pos += 4;
	ft_memcpy(&encoding[pos], champ->header->prog_name, ft_strlen(champ->header->prog_name)); // PROGRAM NAME
	pos += PROG_NAME_LENGTH;
	pos += 4;
	int32_to_bytecode(encoding, pos, champ->pos, 4); // SIZE OF EXEC CODE
	pos += 4;
	ft_memcpy(&encoding[pos], champ->header->comment, ft_strlen(champ->header->comment)); // COMMENT
	pos += COMMENT_LENGTH;
	pos += 4;
	ft_memcpy(&encoding[pos], code, (size_t)champ->pos);
	write(fd, encoding, (size_t)len);
	ft_printf("Writing output program to %s\n", champ->file_name);
	free(encoding);
}

uint8_t	code_encoded_byte(t_token *token, int op)
{
	uint8_t	byte;
	int		i;

	i = 0;
	byte = 0;
	while (i < g_op[op].args_num)
	{
		byte |= token->param_type[i] << 2 * (4 - i - 1);
		i++;
	}
	return (byte);
}
