/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:25:42 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/17 15:55:34 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	call_of_hooks(int key, t_mlx_need *mlx_st)
{
	int	tof;

	if (key == 0)
		a_key(mlx_st);
	else if (key == 1)
		s_key(mlx_st);
	else if (key == 2)
		d_key(mlx_st);
	else if (key == 13)
		w_key(mlx_st);
	else if (key == 53)
	{
		mlx_destroy_window(mlx_st->mlx, mlx_st->mlx_win);
		exit (0);
	}
	else
		return (0);
	return (1);
}

void	what_if(t_mlx_need *mlx_st)
{
	int	move;

	move = 0;
	if (mlx_key_hook(mlx_st->mlx_win, call_of_hooks, mlx_st) == 1)
	{
		move++;
		printf("move n%d", move);
	}
	mlx_hook(mlx_st->mlx_win, 17, 1L < 17, ft_end_game, mlx_st);
}
