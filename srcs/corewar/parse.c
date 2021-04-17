/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:40:41 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/04/03 13:40:43 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Check the magic number
// 
//

#include "../../includes/op.h"
#include "../../includes/corewar.h"

void parse_input(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        printf("av[%d] = [%s]\n", i, av[i]);
        if (av[i][0] == '-')
            parse_flag(av[i]);
        else
            parse_player(av[i]);
        i++;
    }
}

void parse_flag(char *flag)
{
    printf("in parse_flag\n");

    //-n -> 1 onwards and cannot exceed the number of players inputted
}

void parse_player(char *player)
{
    printf("in parse_player\n");
}