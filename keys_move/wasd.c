/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:46:34 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/17 15:57:44 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

int	w_key(t_mlx_need *mlx_st)
{
	t_vtr	p;

	p.y = mlx_st->map->p_place.y;
	p.x = mlx_st->map->p_place.x;
	if (mlx_st->map->reading[p.y - 1][p.x] != '1')
	{
		if (mlx_st->map->reading[p.y - 1][p.x] == 'C')
		{
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, p.x * 32, (p.y - 1) * 32);
			print_move(p.x, p.y - 1, 1, mlx_st);
			mlx_st->map->reading[p.y - 1][p.x] = '0';
			mlx_st->map->points++;
		}
		else if (mlx_st->map->reading[p.y - 1][p.x] == 'E')
			if (mlx_st->map->points == mlx_st->map->all_points)
				ft_end_game(mlx_st);
		else
			print_move(p.x, p.y - 1, 1, mlx_st);
		return (1);
	}
	return (0);
}

int	s_key(t_mlx_need *mlx_st)
{
	t_vtr	p;

	p.y = mlx_st->map->p_place.y;
	p.x = mlx_st->map->p_place.x;
	if (mlx_st->map->reading[p.y + 1][p.x] != '1')
	{
		if (mlx_st->map->reading[p.y + 1][p.x] == 'C')
		{
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, p.x * 32, (p.y + 1) * 32);
			print_move(p.x, p.y + 1, 3, mlx_st);
			mlx_st->map->reading[p.y + 1][p.x] = '0';
			mlx_st->map->points++;
		}
		else if (mlx_st->map->reading[p.y + 1][p.x] == 'E')
			if (mlx_st->map->points == mlx_st->map->all_points)
				ft_end_game(mlx_st);
		else
			print_move(p.x, p.y - 1, 3, mlx_st);
		return (1);
	}
	return (0);
}

int	a_key(t_mlx_need *mlx_st)
{
	t_vtr	p;

	p.y = mlx_st->map->p_place.y;
	p.x = mlx_st->map->p_place.x;
	if (mlx_st->map->reading[p.y][p.x - 1] != '1')
	{
		if (mlx_st->map->reading[p.y][p.x - 1] == 'C')
		{
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, (p.x - 1) * 32, p.y * 32);
			print_move(p.x - 1, p.y, 0, mlx_st);
			mlx_st->map->reading[p.y][p.x - 1] = '0';
			mlx_st->map->points++;
		}
		else if (mlx_st->map->reading[p.y][p.x - 1] == 'E')
			if (mlx_st->map->points == mlx_st->map->all_points)
				ft_end_game(mlx_st);
		else
			print_move(p.x - 1, p.y, 0, mlx_st);
		return (1);
	}
	return (0);
}

int	d_key(t_mlx_need *mlx_st)
{
	t_vtr	p;

	p.y = mlx_st->map->p_place.y;
	p.x = mlx_st->map->p_place.x;
	if (mlx_st->map->reading[p.y][p.x + 1] != '1')
	{
		if (mlx_st->map->reading[p.y][p.x + 1] == 'C')
		{
			mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
				mlx_st->img_back.img, (p.x + 1) * 32, p.y * 32);
			print_move(p.x + 1, p.y, 2, mlx_st);
			mlx_st->map->reading[p.y][p.x + 1] = '0';
			mlx_st->map->points++;
		}
		else if (mlx_st->map->reading[p.y][p.x - 1] == 'E')
			if (mlx_st->map->points == mlx_st->map->all_points)
				ft_end_game(mlx_st);
		else
			print_move(p.x + 1, p.y, 2, mlx_st);
		return (1);
	}
	return (0);
}

int	ft_end_game(t_mlx_need *mlx_st)
{
	mlx_destroy_window(mlx_st->mlx, mlx_st->mlx_win);
	exit (0);
	return (0);
}
