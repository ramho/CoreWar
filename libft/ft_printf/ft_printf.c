/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:19:19 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/03/09 14:25:43 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' ||
			c == '%');
}

char		is_flag_char(char c)
{
	return (c == 'h' || c == 'l' || c == 'L' || c == ' ' || c == '-' ||
			c == '+' || c == '#' || c == '0' || c == 'j');
}

int			parse_format(const char *format, int *i, t_base *all)
{
	int		j;
	char	*str;

	j = 0;
	*i += 1;
	while (!(ft_isalpha(format[*i]) || format[*i] == '%') && format[*i] != '\0')
	{
		*i += 1;
		j++;
	}
	while (is_flag_char(format[*i]) && format[*i + 1] != '\0')
	{
		*i += 1;
		j++;
	}
	if (!(str = ft_strsub(format, *i - j, j + 1)))
		return (-1);
	if ((light_flags(all, str)) == -1)
		return (free_2(str));
	free(str);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_base	*all;
	int		i;
	int		count;

	i = 0;
	all = malloc(sizeof(t_base));
	all->count = 0;
	va_start(all->args, format);
	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%' && format[i + 1])
		{
			if ((parse_format(format, &i, all)) == -1)
				return (free_1(all));
		}
		else if (format[i] == '%' && !(format[i + 1]))
			return (all->count);
		else
			all->count += write(1, &format[i], 1);
		i++;
	}
	count = all->count;
	va_end(all->args);
	free(all);
	return (count);
}
