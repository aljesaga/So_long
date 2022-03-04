/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:38:23 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/04 12:24:14 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_game_struct
{
	int		high;
	int		width;
	int		player_x;
	int		player_y;
	int		all_points;
	char	**reading;
	int		points;
	int		exit_x;
	int		exit_y;
	int		player;
	int		exit;

}	t_game_struct;

/* so_long */

void	ft_free_lts(t_game_struct *map);
int		main(int arc, char **arv);

/* maping */
/* prints */

void	send_error(int line, int point, int action);
int		height(char *arv);

/* analysis */

int		get_type(char *arv);
void	plus_values(int x, int y, char k, t_game_struct *map);
void	other_line(char *str, int line, int length, t_game_struct *map);
void	error_map(char *str, int check, int end, t_game_struct *map);
void	analysis(int fd, t_game_struct *game_map, int end);
#endif
