/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:22:24 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/03 13:55:05 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game_struct *map_o, t_mlx_need *mlx_st)
{
	if (map_o->width * 32 > 1921 || map_o->high * 32 > 1080)
	{
		printf("Error\n map too big\n");
		ft_free_map(map_o);
		exit (0);
	}
	mlx_st->mlx = mlx_init();
	mlx_st->mlx_win = mlx_new_window(mlx_st->mlx, (map_o->width * 32 + 32),
			(map_o->high * 32 + 32), "SO_LONG");
	ft_charge_arts(mlx_st);
	ft_add_arts(mlx_st, map_o);
	mlx_st->map = map_o;
	what_if(mlx_st);
	mlx_loop(mlx_st->mlx);
}

int	main(int arc, char **arv)
{
	int				fd;
	t_mlx_need		mlx_st;
	t_game_struct	game_map;

	if (arc == 2)
	{
		if (get_type(arv[1]) == 1)
		{
			game_map.high = height(arv[1]);
			fd = open(arv[1], O_RDONLY);
			analysis(fd, &game_map, game_map.high);
			close(fd);
			load_map(&game_map, &mlx_st);
		}
		else
			printf("incompatible format\n");
	}
	else
		printf("number of maps not exact\n");
	system("leaks so_long");
	return (0);
}
