/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:25:42 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/02 14:37:50 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	call_of_hooks(int key, t_mlx_need *mlx_st)
{
	int	tof;

	tof = 0;
	if (key == 0 || key == 123)
		tof = a_key(mlx_st);
	else if (key == 1 || key == 125)
		tof = s_key(mlx_st);
	else if (key == 2 || key == 124)
		tof = d_key(mlx_st);
	else if (key == 13 || key == 126)
		tof = w_key(mlx_st);
	else if (key == 53)
	{
		mlx_destroy_window(mlx_st->mlx, mlx_st->mlx_win);
		exit (0);
	}
	if (tof == 1)
	{
		mlx_st->moves += 1;
		printf("Moves : %d\n", mlx_st->moves);
	}
	return (tof);
}

void	what_if(t_mlx_need *mlx_st)
{
	mlx_key_hook(mlx_st->mlx_win, call_of_hooks, mlx_st);
	mlx_hook(mlx_st->mlx_win, 17, 1L < 17, ft_end_game, mlx_st);
}
