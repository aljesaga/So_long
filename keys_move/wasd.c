/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:46:34 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/15 11:31:28 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	w_key(t_game_struct *map, void *mlx)
{
	int	y;
	int	x;

	y = map->p_place->y;
	x = map->p_place->x;
	if (y - 1 != 0)
	{
		if (map->reading[y - 1][x] != '1' && map->reading[y - 1][x] == 'C')
		{
			map->reading[y - 1][x] = 'P';
			map->reading[y][x] = '0';
			map->p_place->y--;
			map->points++;
		}
		else if (map->reading[y - 1][x] != 1)
		{
			map->reading[y - 1][x] = 'P';
			map->reading[y][x] = '0';
			map->p_place->y--;
		}
		if (map->reading[y - 1][x] == 'E')
			if (map->points == map->all_points)
				ft_end_map(map, mlx);
	}
}

void	s_key(t_game_struct *map, void *mlx)
{
	int	y;
	int	x;

	y = map->p_place->y;
	x = map->p_place->x;
	if (y + 1 != 0)
	{
		if (map->reading[y + 1][x] != '1' && map->reading[y + 1][x] == 'C')
		{
			map->reading[y + 1][x] = 'P';
			map->reading[y][x] = '0';
			map->p_place->y++;
			map->points++;
		}
		else if (map->reading[y + 1][x] != '1')
		{
			map->reading[y + 1][x] = 'P';
			map->reading[y][x] = '0';
			map->p_place->y++;
		}
		if (map->reading[y + 1][x] == 'E')
			if (map->points == map->all_points)
				ft_end_map(map, mlx);
	}
}

void	a_key(t_game_struct *map, void *mlx)
{
	int	y;
	int	x;

	y = map->p_place->y;
	x = map->p_place->x;
	if (x - 1 != 0)
	{
		if (map->reading[y][x - 1] != '1' && map->reading[y][x - 1] == 'C')
		{
			map->reading[y][x - 1] = 'P';
			map->reading[y][x] = '0';
			map->p_place->x--;
			map->points++;
		}
		else if (map->reading[y][x - 1] != '1')
		{
			map->reading[y][x - 1] = 'P';
			map->reading[y][x] = '0';
			map->p_place->x--;
		}
		if (map->reading[y][x - 1] == 'E')
			if (map->points == map->all_points)
				ft_end_map(map, mlx);
	}
}

void	d_key(t_game_struct *map, void *mlx)
{
	int	y;
	int	x;

	y = map->p_place->y;
	x = map->p_place->x;
	if (x + 1 != 0)
	{
		if (map->reading[y][x + 1] != '1' && map->reading[y][x + 1] == 'C')
		{
			map->reading[y][x + 1] = 'P';
			map->reading[y][x] = '0';
			map->p_place->x++;
			map->points++;
		}
		else if (map->reading[y][x + 1] != '1')
		{
			map->reading[y][x + 1] = 'P';
			map->reading[y][x] = '0';
			map->p_place->x++;
		}
		if (map->reading[y][x + 1] == 'E')
			if (map->points == map->all_points)
				ft_end_map(map, mlx);
	}
}

void	ft_end_map(t_game_struct *map, void *mlx)
{
	ft_free_lts(map);
	free(mlx);
	exit (0);
}
