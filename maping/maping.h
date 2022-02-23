/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:26:59 by alsanche          #+#    #+#             */
/*   Updated: 2022/02/23 17:31:32 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPING_H
# define MAPING_H

# include "../../Libft/libft.h"
# include "../so_long.h"
# include <unistd.h>
# include <stdio.h>

/* prints */

void	send_error(int line, int point, int action);
int		height(char *arv);

/* analysis */

int		type(char *arv);
void	plus_values(int x, int y, char k, t_game_struct *map);
void	other_line(char *str, int line, int length, t_game_struct *map);
void	error_map(char *str, int check, int end, t_game_struct *map);
void	analysis(int fd, t_game_struct *game_map, int end);

#endif