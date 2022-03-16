/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:22:24 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/16 19:50:54 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(int fd, t_game_struct *map, t_mlx_need *mlx_a)
{
	mlx_a->mlx_win = mlx_new_window(mlx_a->mlx, (map->width * 32),
			(map->high * 32), "SO_LONG");
	mlx_a->img_back = ft_new_sprite(mlx_a->mlx, "./arts/flor.xmp");
	mlx_a->img_wall = ft_new_sprite(mlx_a->mlx, "./arts/wall.xmp");
	mlx_a->img_player = ft_new_sprite(mlx_a->mlx, "./arts/player.xmp");
	mlx_a->img_coll = ft_new_sprite(mlx_a->mlx, "./arts/colection.xmp");
	mlx_a->img_exit = ft_new_sprite(mlx_a->mlx, "./arts/exit.xmp");
	ft_add_arts(mlx_a, map);
	mlx_loop(mlx_a->mlx);
}

void	ft_free_lts(t_game_struct *map, int check)
{
	map->p_place.x = 0;
	map->p_place.y = 0;
	map->player = 0;
	map->e_place.x = 0;
	map->e_place.y = 0;
	map->exit = 0;
	map->points = 0;
	map->all_points = 0;
	map->width = 0;
	while (map->high-- > 0)
		free(map->reading[map->high]);
	free(map->reading[0]);
}

int	main(int arc, char **arv)
{
	int				fd;
	t_mlx_need		mlx_a;
	t_game_struct	game_map;

	if (arc == 2)
	{
		if (get_type(arv[1]) == 1)
		{
			game_map.high = height(arv[1]);
			fd = open(arv[1], O_RDONLY);
			analysis(fd, &game_map, game_map.high);
			mlx_a.mlx = mlx_init();
			load_map(fd, &game_map, &mlx_a);
		}
		else
			printf("incompatible format\n");
	}
	else
		printf("number of maps not exact\n");
	close(fd);
	return (0);
}
