/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:07:24 by rhoorntj          #+#    #+#             */
/*   Updated: 2021/04/03 13:07:25 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#   include <stdio.h>


int main(int ac, char **av);

void parse_input(int ac, char **av);
void parse_flag(char *flag);
void parse_player(char *player);

#endif
