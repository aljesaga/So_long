/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:22:24 by alsanche          #+#    #+#             */
/*   Updated: 2022/03/08 16:56:07 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(int fd, t_game_struct *map, t_mlx_need *mlx_all)
{
	mlx_all->mlx_win = mlx_new_window(mlx_all->mlx, map->width, map->high, "SO_LONG");
	mlx_all->img_back = ft_new_img(mlx_all->mlx, map->width, map->high);
	mlx_all->img_wall = ft_new_sprite(mlx_all->mlx, "./arts/wall.xmp");
	mlx_all->img_player = ft_new_sprite(mlx_all->mlx, "./arts/player.xmp");
	mlx_all->img_coll = ft_new_sprite(mlx_all->mlx, "./arts/colection.xmp");
	mlx_all->img_exit = ft_new_sprite(mlx_all->mlx, "./arts/exit.xmp");

void	ft_free_lts(t_game_struct *map)
{
	map->p_place->x = 0;
	map->p_place->y = 0;
	map->player = 0;
	map->e_place->x = 0;
	map->e_place->y = 0;
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
	t_mlx_need		*mlx_all;
	t_game_struct	*game_map;

	if (arc == 2)
	{
		if (get_type(arv[1]) == 1)
		{
			fd = open(arv[1]);
			game_map->high = height(arv[1]);
			analysis(fd, game_map, game_map->high);
			mlx_all->mlx = mlx_init();
			load_map(fd, game_map, mlx_all);
		}
	}
	else
		printf("number of maps not exact\n");
	close(fd);
	return (0);
}
