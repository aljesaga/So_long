/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:46:34 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/08 17:48:03 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	W_key(t_game_struct *map, void *mlx)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_y;
	if (y - 1 != 0)
	{
		if (map->reading[y - 1][x] != '1' && map->reading[y - 1][x] == 'C')
		{
			map->reading[y - 1][x] = 'P';
			map->reading[y][x] = '0';
			map->player_y--;
			map->points++;
		}
		else if (map->reading[y - 1][x] != 1)
		{
			map->reading[y - 1][x] = 'P';
			map->reading[y][x] = '0';
			map->player_y--;
		}
		if (map->reading[y - 1][x] == 'E')
			if (map->points == map->all_points)
				ft_end_map(map, mlx);
	}
}

void	S_key(t_game_struct *map, void *mlx)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_y;
	if (y + 1 != 0)
	{
		if (map->reading[y + 1][x] != '1' && map->reading[y + 1][x] == 'C')
		{
			map->reading[y + 1][x] = 'P';
			map->reading[y][x] = '0';
			map->player_y++;
			map->points++;
		}
		else if (map->reading[y + 1][x] != '1')
		{
			map->reading[y + 1][x] = 'P';
			map->reading[y][x] = '0';
			map->player_y++;
		}
		if (map->reading[y + 1][x] == 'E')
			if (map->points == map->all_points)
				ft_end_map(map, mlx);
	}
}

void	A_key(t_game_struct *map, void *mlx)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_y;
	if (x - 1 != 0)
	{
		if (map->reading[y][x - 1] != '1' && map->reading[y][x - 1] == 'C')
		{
			map->reading[y][x - 1] = 'P';
			map->reading[y][x] = '0';
			map->player_x--;
			map->points++;
		}
		else if (map->reading[y][x - 1] != '1')
		{
			map->reading[y][x - 1] = 'P';
			map->reading[y][x] = '0';
			map->player_x--;
		}
		if (map->reading[y][x - 1] == 'E')
			if (map->points == map->all_points)
				ft_end_map(map, mlx);
	}
}

void	D_key(t_game_struct *map, void *mlx)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_y;
	if (x + 1 != 0)
	{
		if (map->reading[y][x + 1] != '1' && map->reading[y][x + 1] == 'C')
		{
			map->reading[y][x + 1] = 'P';
			map->reading[y][x] = '0';
			map->player_x++;
			map->points++;
		}
		else if (map->reading[y][x + 1] != '1')
		{
			map->reading[y][x + 1] = 'P';
			map->reading[y][x] = '0';
			map->player_x++;
		}
		if (map->reading[y][x + 1] == 'E')
			if (map->points == map->all_points)
				ft_end_map(map, mlx);
	}
}

void	ft_end_map(t_game_struct *map, void *mlx)
{
	ft_free_lst(map);
	free(mlx);
	exit (0);
}